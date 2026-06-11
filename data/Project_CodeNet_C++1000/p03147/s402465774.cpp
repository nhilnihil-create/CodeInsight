#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;cin>>n;
    int h[n];
    for(int i = 0;i<n;i++) cin>>h[i]; 
    int ans = 0;
    while(true){
      int k0 = 0;
      for(int i = 0;i<n;i++){
        if(h[i] == 0) k0++;
      }
      if(k0 == n){
        cout<<ans;
        return 0;
      }
      int zgai = 0;//0以外が出た回数
      int ss = 1000;//最小値
      int soko = n;
      for(int i = 0;i<n;i++){
      	if(h[i] != 0){
          zgai+= 1;
          ss = min(ss,h[i]);
        }
        if(zgai != 0){
          if(h[i] == 0){
            soko = i;
            break;
          }
        }
      }
      //cout<<ss<<endl;;
      for(int i = 0;i<soko;i++){
        if(h[i] == 0) continue;
      	h[i]-=ss;
      }
      ans+= ss;
    }
    return 0;
}