#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int c[25];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n)cin >> d[i];
    c[0] = 1;
    sort(ALL(d));
    rep(i,n){
        if((i%2)==0){
            int a = d[i];
            int b = 24 - d[i];
            c[min(a,b)]++;
        }else{
            int a = d[i];
            int b = 24 - d[i];
            c[max(a,b)]++;
        }
    }
    int ans = 24;
    int cnt = 1;
    for(int i=1;i<24;i++){
        if(c[i]==0)cnt++;
        else{
            ans = min(ans,cnt);
            cnt = 1;
        }
    }
    
    ans = min(ans,cnt);
    if(d[0]==0)ans = 0;
    rep(i,24)if(c[i]>=2)ans = 0;
    cout << ans << endl;
}