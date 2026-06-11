#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

bool sosuhantei(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return n!=1;
}

int main(){
  vector<int> v;
  for(int i=1;i<=55555;i+=5){
    if(sosuhantei(i)){
      v.push_back(i);
    }
  }
  
  int n;
  cin>>n;
  rep(i,0,n){
    cout<<v[i];
    if(i==n-1){
      cout<<endl;
    }
    else{
      cout<<' ';
    }
  }
}