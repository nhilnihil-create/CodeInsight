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

vector<int> h(200,0);
int n;

void solve(int id){
    int left = id;
    int right = id;
    while(h[left]>0){
        if(left==0) break;
        else left--;
    }
    while(h[right]>0){
        if(right==n-1) break;
        else right++;
    }
    for(int i=left; i<=right;i++){
        h[i]--;
    }
}

int main(){
    cout << fixed << setprecision(10);
    cin >> n;
    rep(i,n) cin >> h[i];
    int ans = 0;
    bool ok = 1;
    while(ok){
        ok = 0;
        rep(i,n){
            if(h[i]>0){
                solve(i);
                ok = 1;
                ans++;
            }
        }
        if(ok==0) break;
    }
    cout << ans << endl;
    return 0;
}