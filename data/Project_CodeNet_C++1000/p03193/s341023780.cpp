#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,h,w,h1,w1;
  cin>>n>>h>>w;
  int count=0;
  for(int i=0;i<n;i++){
    cin>>h1>>w1;
    if(h1>=h && w1>=w){
      count++;
    }
  }
  cout<<count<<endl;
}