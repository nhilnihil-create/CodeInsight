#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll n; cin >> n;
    ll a[n], sum = 0;
    for(int i = 0; i < n; ++i){ 
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    sum -= a[n - 1];
    if(a[n - 1] < sum) cout << "Yes\n";
    else cout << "No\n";
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}