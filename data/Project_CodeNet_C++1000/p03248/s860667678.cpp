#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n'
#define debug_arr(a , n) for(int i = 0 ; i < n ; i++)cout << a[i] << " "
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define inf 1000000000
#define mod 1000000007

const int max_n = 1e5 + 9;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] == '0' || s[n-1] == '1'){
        cout << -1;
        return 0;
    }
    vector<int> vec;
    for(int i = 0 ; i < n-1 ; i++){
        if(s[i] != s[n-2-i]){
            cout << -1;
            return 0;
        }
        if(s[i] == '1'){
            vec.pb(i);
        }
    }

    int k = vec.size();
    int cnt = 1;
    for(int i = 0 ; i < k ; i++){
        cout << cnt << " " << cnt + 1 << endl;
        cnt++;
    }
    cnt++;
    for(int i = 1 ; i < k ; i++){
        for(int j = 0 ; j < vec[i] - vec[i-1] - 1 ; j++){
            cout << i+1 << " " << cnt++ << endl;
        }
    }
    return 0;
}