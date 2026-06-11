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
const int N = 5e5 + 10;

void solve(){
     int n;cin >> n;
     vector<string>s(n);
     for(int i = 0;i<n;i++) cin >> s[i];
     for(int i = 0;i<n-1;i++)
     for(int j = i+1;j<n;j++){
        if(s[i]==s[j]) {cout << "No";return;}
     }
     for(int i = 0;i<n-1;i++){
     char c = s[i][s[i].size()-1];
     if(s[i+1][0]!=c){cout <<"No";return;}
     }
     cout << "Yes";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
