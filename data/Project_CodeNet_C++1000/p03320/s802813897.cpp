#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<long long> s;
void go(int x){
  if(x==1)
    for(int i=1;i<=9;i++)
      s.push_back(i);
  else if(x==2)
    for(int i=19;i<=99;i+=10)
      s.push_back(i);
  else{
    long long o=9;
    long long oo=10;
    for(int i=0;i<x-3;i++){
      o*=10;
      o+=9;
      oo*=10;
    }
    for(int i=10;i<=99;i++)
      s.push_back(i*oo+o);
  }
}
char ss[20];
pair<long double,long long> snuke[2001];
void choose(){
  for(int i=0;i<s.size();i++){
    sprintf(ss,"%lld",s[i]);
    int sum=0;
    for(int j=0;j<strlen(ss);j++)
      sum+=ss[j]-'0';
    snuke[i].first=(long double)(s[i]*1.0)/(sum*1.0);
    snuke[i].second=i;
  }
}
int main(){
  int k;cin>>k;
  s.clear();
  for(int i=1;i<=15;i++)
    go(i);
  long long o[9]={100999999999999,101999999999999,102999999999999,103999999999999,104999999999999,
  105999999999999,106999999999999,107999999999999,108999999999999};
  bool ok;
  int cnt=0;
  s.insert(s.begin()+1098,o,o+9);
  choose();
  for(int i=0;i<s.size();i++){
    ok=1;
    for(int j=i+1;j<s.size();j++)
      if(snuke[i].first>snuke[j].first)
        {ok=0;
         break;}
    if(ok==1 && cnt<k){
      cout<<s[i]<<endl;
      cnt++;}
  }
  return 0;
}