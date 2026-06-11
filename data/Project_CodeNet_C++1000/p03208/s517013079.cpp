#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007

using namespace std;
int main(){
    FAST
    ll n,k; cin >> n >> k;
    ll a[n];
    scanArray(a,n);
    sort(a,a+n);
    ll mndf = 1e10;
    for(ll i=0;i+k-1<n;i++){
            if(i==n-1){
                break;
            }
            mndf=min(mndf,abs(a[i]-a[i+k-1]));
    }
    cout << mndf << endl;

    return 0;
}
