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
    string s,t;cin >> s >> t;
    int n = s.size();
    vector<int>cnt(26);
    vector<int>cnt2(26);
    for(int i = 0;i<n;i++) cnt[s[i]-'a']++;
    sort(cnt.begin(),cnt.end());
    for(int i = 0;i<n;i++) cnt2[t[i]-'a']++;
    sort(cnt2.begin(),cnt2.end());
    bool ok = 1;
    for(int i = 0;i<26;i++){
        if(cnt[i]!=cnt2[i]) ok = 0;
    }
    if(ok) cout <<"Yes"<<endl;
    else cout <<"No"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
