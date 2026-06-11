#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<cmath>
#include<vector>
#include<map>
#include<random>
using namespace std;

int main(){
    int n,m;cin >> n >> m;
    int k[n];
    int a[n+1][m+1];
    int ans = 0;
    int t[35] = {};
    for(int i = 0;i < n;i++){
        cin >> k[i];
        for(int j = 0;j < k[i];j++){
            cin >> a[i][j];
            t[a[i][j]] += 1;
        }
    }
    for(int i = 0;i < m+1;i++){
        //cout << t[i] << " ";
        if(t[i] == n)ans++;
    }
    cout << endl;

    cout << ans << endl;

}