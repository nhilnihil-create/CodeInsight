#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int A,B; cin >> A >> B;
    char c[100][100];
    rep(i,50){
        rep(j,100){
            c[i][j]='#';
        }
    }
    rng(i,50,100){
        rep(j,100){
            c[i][j]='.';
        }
    }
    int cnt=A-1;
    for(int i=1;i<50;i+=2){
        for(int j=1;j<100;j+=2){
            if(cnt==0) break;
            c[i][j]='.';
            cnt--;
        }
        if(cnt==0) break;
    }
    cnt=B-1;
    for(int i=51;i<100;i+=2){
        for(int j=1;j<100;j+=2){
            if(cnt==0) break;
            c[i][j]='#';
            cnt--;
        }
        if(cnt==0) break;
    }
    cout << 100 << " " << 100 << endl;
    rep(i,100) {
        rep(j,100){
            cout << c[i][j];
        }
        cout << endl;
    }
}