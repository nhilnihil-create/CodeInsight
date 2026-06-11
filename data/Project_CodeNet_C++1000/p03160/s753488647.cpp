#include <iostream>
/*#include <bits/stdc++.h>*/
using namespace std;
int md=998244353;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int cost[n];
    cost[0]=0;
    cost[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;++i) cost[i]=min(cost[i-2]+abs(a[i]-a[i-2]),cost[i-1]+abs(a[i]-a[i-1]));
    cout<<cost[n-1];
}