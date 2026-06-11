#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(ll i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int>l(n);
    rep(i, 0, n)cin >> l[i];
    int MP = 100100100;
    int cnt = 0;
    for(int bit1=0; bit1<(1<<n); bit1++){
        for(int bit2=0; bit2<(1<<n); bit2++){
            int tempMP = 0;
            vector<int>v(4);
            rep(i, 0, n){
                if(bit1&(1<<i)&&bit2&(1<<i)){
                    if(v[0]!=0)tempMP += 10;
                    v[0]+=l[i];
                }else if(!(bit1&(1<<i))&&bit2&(1<<i)){
                    if(v[1]!=0)tempMP += 10;
                    v[1]+=l[i];
                }else if(bit1&(1<<i)&&!(bit2&(1<<i))){
                    if(v[2]!=0)tempMP += 10;
                    v[2]+=l[i];
                }else{
                    v[3]+=l[i];
                }
            }
            if(v[0]==0||v[1]==0||v[2]==0)continue;
            tempMP += abs(v[0]-a);
            tempMP += abs(v[1]-b);
            tempMP += abs(v[2]-c);
            MP = min(MP, tempMP);
            cnt++;
        }
    }
    //cout << cnt << endl;
    cout << MP << endl;
}