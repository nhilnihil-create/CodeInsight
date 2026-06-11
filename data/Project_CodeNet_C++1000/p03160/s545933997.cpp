#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    fast_io();
    
    int n;
    cin>>n;

    ll a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    ll b[n];
    b[0] = 0;
    b[1] = abs(a[1]-a[0]);

    for(int i=2; i<n; i++){
        b[i] = min(abs(a[i]-a[i-1])+b[i-1], abs(a[i]-a[i-2])+b[i-2]);
    }

    cout<<b[n-1]<<"\n";

    return 0;

}
  