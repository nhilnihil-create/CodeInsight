#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <numeric>
#include <bitset>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
string s;
int x, y;
vector<int> compress;
bitset<16001> xbit, ybit;
/**********************************************/

signed main(){
    cin >> s;
    cin >> x >> y;
    
    compress.pb(0);
    REP(i, s.size()){
        if(s[i] == 'T') compress.pb(0);
        else compress.back()++;
    }

    xbit[8000 + compress.front()] = true;
    ybit[8000] = true;

    FOR(i, 1, compress.size()){
        if(i%2 == 0){
            xbit = (xbit << compress[i]) | (xbit >> compress[i]);
        }else{
            ybit = (ybit << compress[i]) | (ybit >> compress[i]);
        }
    }

    if(xbit[8000 + x] && ybit[8000 + y]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
