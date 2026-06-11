#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

int main(){
    int n, k;   cin >> n >>k;
    string s;   cin >> s;
    vector<ll> a;
    if(s[0]=='0') a.push_back(0);

    int cnt=1;
    REP(i, n){
        if(s[i]==s[i+1]){
            cnt += 1;
            if(i==n-1) a.push_back(cnt);
        }else{
            a.push_back(cnt);
            cnt = 1;
        }
    }
    if(s.back()=='0') a.push_back(0);
    vector<ll> sum((int)a.size()+1, 0);
    REP(i, a.size())    sum[i+1] = sum[i]+a[i];
    
    ll res=0;
    for(int left=0; left<sum.size(); left+=2){
        int right = left+2*k+1;
        if(sum.size()<=right) right = sum.size()-1;
        res = max(res, sum[right]-sum[left]);
    }
    cout << res << endl;
}