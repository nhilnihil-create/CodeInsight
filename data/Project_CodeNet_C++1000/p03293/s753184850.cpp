#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;

int main(){
  string S,T;
  cin>>S>>T;
  int N=S.length();
  rep(i,N){
    if(S==T){
      cout<<"Yes"<<endl;
      return 0;
    }
    S=S[N-1]+S.substr(0,N-1);
  }
  cout<<"No"<<endl;
}