#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;

int main(){

 
  int N,M;
  
  map<long long,int> mp;
  
  cin>>N;
  rep(i,N){
   
    int a;
    cin>>a;
    mp[a]++;
    
  }

  cin>>M;
  
  rep(j,M){
    
    int b;
    cin>>b;
    if(mp[b]==0){cout<<"NO"<<endl;return 0;}
    
    mp[b]--;
  }
  cout<<"YES"<<endl;
}