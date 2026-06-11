#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  map<int,int>m;
  rep(i,4){
    int t;cin>>t;
    m[t]++;
  }
  if(m[1]&&m[9]&&m[7]&&m[4]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}