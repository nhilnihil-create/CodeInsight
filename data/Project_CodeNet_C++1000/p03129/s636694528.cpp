#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MAX 300004

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    if( k <= (n+1)/2) cout<<"YES";
    else cout<<"NO";
    return 0;
}