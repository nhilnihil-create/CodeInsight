#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll vec[n][3];
  ll zero=0;
  for(int i=0;i<n;i++){
    cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
  }
  for(ll x=0;x<=100;x++){
    for(ll y=0;y<=100;y++){
      for(int z=0;z<n;z++){
        ll h=vec[z][2]+abs(vec[z][0]-x)+abs(vec[z][1]-y);
        int t=0;
        for(int i=0;i<n;i++){
          if(i==z){
            continue;
          }
          if(max(h-abs(x-vec[i][0])-abs(y-vec[i][1]),zero)!=vec[i][2]){
            t++;
          }
        }
        if(t==0){
          if(h>0){
            cout<<x<<" "<<y<<" "<<h<<endl;
            return 0;
          }
        }
      }
    }
  }
}