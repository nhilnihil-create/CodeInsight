#include <iostream>
// #include <bits/stdc++.h>
// #include <cstdint> 
// #include <limits>
using namespace std;
int md=998244353;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int cost[n];
    for(int i=0;i<n;++i) cost[i] = INT32_MAX;
    cost[0]=0;
    for(int i=1;i<n;++i){
        for(int j=1;j<=k && i-j>=0;++j){
            cost[i] = min(cost[i],cost[i-j]+abs(a[i]-a[i-j]));
        }
    }
    cout<<cost[n-1];
}