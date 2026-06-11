#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int bit_counter(int x){
    if(x==0) return 0;
    return bit_counter(x>>1)+(x&1);
}
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    set<string> si[5];
    rep(i,n){
        string s;
        cin >> s;
        if(s[0] == 'M') si[0].insert(s);
        if(s[0] == 'A') si[1].insert(s);
        if(s[0] == 'R') si[2].insert(s);
        if(s[0] == 'C') si[3].insert(s);
        if(s[0] == 'H') si[4].insert(s);
    }
    ll sum = 0;
    rep(i,1<<5){
        ll now = 1;
        if(bit_counter(i)!=3) continue;
        rep(j,5){
            if((i>>j)&1){
                now *= (ll)si[j].size();
            }
        }
        sum += now;
    }
    cout << sum << endl;
    return 0;
}