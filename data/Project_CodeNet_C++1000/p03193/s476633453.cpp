#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n,h,w;cin>>n>>h>>w;
  int result=0;
  rep(i,n){
    int th,tw;cin>>th>>tw;
    if(th>=h && tw>=w)result++;
  }

  cout<<result<<endl;

  return 0;
}