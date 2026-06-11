#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);rep(i,n)cin >> a[i];
    ll ans = 0;
    ll sum = 0;
    ll temp_xor = 0;
    int left = 0;
    int right = 0;
    for( left= 0; left < n; left++)
    {
        if(left>right)
        {
            right = left;
        }
        while(right < n && (sum+a[right])==(temp_xor^a[right]))
        {
            sum += a[right];
            temp_xor = temp_xor^a[right];
            //cout << sum << " " << temp_xor << endl;
            right++;
        }
        
        ans += right-left;
        // cout << right << endl;
        sum = sum-a[left];
        temp_xor = a[left]^temp_xor;
    }
    cout << ans << endl;
    

}