#include <iostream>
// #include <bits/stdc++.h>
// #include <cstdint> 
// #include <limits>
using namespace std;
int md=998244353;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int points[n][3];
    for(int i=0;i<n;++i) cin>>points[i][0]>>points[i][1]>>points[i][2];
    int result[n][3];
    result[0][0] = points[0][0];
    result[0][1] = points[0][1];
    result[0][2] = points[0][2];
    for(int i=1;i<n;++i){
        result[i][0] = max(result[i-1][1]+points[i][0],result[i-1][2]+points[i][0]);
        result[i][1] = max(result[i-1][0]+points[i][1],result[i-1][2]+points[i][1]);
        result[i][2] = max(result[i-1][1]+points[i][2],result[i-1][0]+points[i][2]);
    }
    int ans = max(result[n-1][0],result[n-1][1]);
    ans = max(ans,result[n-1][2]);
    cout<<ans;
}