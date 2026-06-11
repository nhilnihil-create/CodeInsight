#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;cin>>n;
    int t[n];
    for(int i = 0;i<n;i++) cin>>t[i];
    sort(t,t+n,greater<int>());
    t[0]/=2;
    int g = 0;
    for(int i = 0;i<n;i++){
      g+= t[i];
    }
    cout<<g;
    return 0;
}