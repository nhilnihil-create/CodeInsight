#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
    int n,m;cin >> n >> m;
    vector<int> k(n + 1);
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for(int i = 1;i < n + 1; i++) {
        for(int j = 1; j < m + 1 ; j++){
            a[i][j] = 0;
        } 
    }

    for(int i = 1;i < n + 1 ; i++) {
        cin >> k[i];
        for(int j = 1; j < k[i] + 1; j++){
            cin >> a[i][j];
        } 
    }

  // compute 
    int ans = 0;
    vector<int> suki(m + 1);
    for(int i = 1;i < m + 1; i++) {
            suki[i] = 0;       
    }

    for(int i = 1;i < n + 1; i++) {
        for(int j = 1; j < k[i] + 1 ; j++){
            suki[a[i][j]]++;
        } 
    } 

    for(int i = 1;i < m + 1; i++) {
        if(suki[i] == n){
            ans++;
        }
    }

  // output  
    cout << ans << endl;

}