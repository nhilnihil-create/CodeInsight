#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

int main(){
  string s;
  cin>>s;
  int a=0,b=0,c=0,L=s.length();
  for(int i=0;i<L;i++){
    if(s[i]=='a') a++;
    else if(s[i]=='b') b++;
    else c++;
  }
  int tmpa=a,tmpb=b,tmpc=c;
  tmpa=max({a,b,c});
  tmpc=min({a,b,c});
  tmpb=a+b+c-tmpa-tmpc;
  a=tmpa, b=tmpb, c=tmpc;
  for(int i=1;i<=L;i++){
    if(i%3==1){
      a--;
    }else if(i%3==2){
      b--;
    }else{
      c--;
    }
    if(a<0||b<0||c<0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
