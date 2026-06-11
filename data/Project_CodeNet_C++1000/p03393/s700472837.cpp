#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  string S;
  cin>>S;
  int N=S.size();
  set<char> s;
  for(int i=0;i<N;i++){
    char c=S.at(i);
    s.insert(c);
  }
  bool flag=true;
  for(int i=0;i<26;i++){
    char c=(char)(i+'a');
    if(s.count(c)!=1){
      cout<<S<<c<<endl;
      flag=false;
      break;
    }
  }

  if(flag){
    int i=N-2;
    vector<char> s;
    s.push_back(S.at(N-1));
    while(S.at(i)>S.at(i+1)){
      s.push_back(S.at(i));
      i--;
      if(i<0){
        break;
      }
    }
    if(i<0){
      cout<<-1<<endl;
    }else{
      sort(s.begin(),s.end());
      int k=upper_bound(s.begin(),s.end(),S.at(i))-s.begin();
      S.at(i)=s.at(k);
      for(int j=0;j<=i;j++){
        cout<<S.at(j);
      }
      cout<<endl;
    }
  }
}
