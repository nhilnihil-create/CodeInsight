#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;


void solve(){
    int n,q;cin >> n >> q;
    string s;cin >> s;
    vector<int>pre(n+1,0);
    for(int i = 0;i<n-1;i++){
        pre[i+2] = pre[i+1];
        if(s[i]=='A'&&s[i+1]=='C') pre[i+2]++;
    }
    while(q--){
        int l,r;cin >> l >> r;
        cout << pre[r] - pre[l]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
