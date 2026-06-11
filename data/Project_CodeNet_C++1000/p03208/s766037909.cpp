#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long n,m;cin>>n>>m;
    long h[n];
    for(int i = 0;i<n;i++) cin>>h[i];
    sort(h,h+n,greater<long>());
    long sai = 10000000000;
    for(int i = 0;i<n-m+1;i++){
      if(h[i]-h[i+m-1] <= sai) sai = h[i]-h[i+m-1];
    }
    cout<<sai;
    return 0;
}