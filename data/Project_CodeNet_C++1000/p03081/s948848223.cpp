#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

bool fl(int k,int N,int Q,string s,vector<char> t,vector<char> d){
    int now = k;
    bool ok = false;
    rep(i,Q){
        if(t[i] == s[now]){
            if(d[i] == 'R') now++;
            else now--;
        }
        if(now == -1) ok = true;
    }
    return ok;
}

bool fr(int k,int N,int Q,string s,vector<char> t,vector<char> d){
    int now = k;
    bool ok = false;
    rep(i,Q){
        if(t[i] == s[now]){
            if(d[i] == 'R') now++;
            else now--;
        }
        if(now == N) ok = true;
    }
    return ok;
}

int main(){
    int N,Q; cin >> N >> Q;
    string s; cin >> s;
    vector<char> t(Q),d(Q);
    rep(i,Q) cin >> t[i] >> d[i];
    int ok = -1,ng = N;
    while(ng-ok > 1){
        int mid = (ng+ok)/2;
        if(fl(mid,N,Q,s,t,d)) ok = mid;
        else ng = mid;
    }
    int ok2 = N,ng2 = -1;
    while(ok2-ng2 > 1){
        int mid2 = (ng2+ok2)/2;
        if(fr(mid2,N,Q,s,t,d)) ok2 = mid2;
        else ng2 = mid2;
    }
    int ans = N-(ok+1)-(N-ok2);
    cout << ans << endl;
}