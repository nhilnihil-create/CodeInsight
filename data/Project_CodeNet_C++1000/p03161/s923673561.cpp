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
    
    int n, k;
    cin>>n>>k;

    ll a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    ll b[n];
    b[0] = 0;  

    for(int i=1; i<n; i++){
        ll mindist = INT_MAX;
        for(int j=i-1; j>=0 && j >= i-k; j--){
            mindist = min(mindist, abs(a[i]-a[j])+b[j]);    
        }
        b[i] = mindist;        
    }

    cout<<b[n-1]<<"\n";

    return 0;

}
  