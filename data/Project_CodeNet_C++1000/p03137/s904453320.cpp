#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;


int main() {

    int n,m;
    cin >> n >> m ;
    int x[m];
    for(int i=0;i<m;i++) cin >> x[i] ;

    sort(x,x+m);

    int diff[m-1];
    for(int i=0;i<(m-1);i++){
        diff[i] = x[i+1]-x[i];
    }
    sort(diff,diff+(m-1));

    int ans = 0; 
    for(int i=0;i<m-n;i++){
        ans+=diff[i];
    }

    cout << ans << endl ;

    return 0 ;
}