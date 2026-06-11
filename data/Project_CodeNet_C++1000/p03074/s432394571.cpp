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
    //尺取り法
    int left=0, right=0, sum=0, res=0;
    //for(auto x: a) cout << x << endl;
    while(right<a.size()){
        
        while(right<a.size() && right-left<=2*k){
            sum += a[right++];
        }
        //cout << sum << endl;
        res = max(sum, res);
        sum -= a[left]+a[left+1];
        left += 2;
    }
    cout << res << endl;
}