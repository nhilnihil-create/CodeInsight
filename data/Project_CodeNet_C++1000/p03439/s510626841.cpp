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

    int N; cin >> N;
    int cnt=0;
    int frag,frag2,pos=0;
    string s;
    int l=N-1,r=0;
    while(l-r>1){
        if(!cnt) {
            cnt++;
            cout << 0 << flush << endl;
            continue;
        }
        cin >> s;
        if(s[0]=='V') return 0;
        if(cnt==1){
            frag=(s[0]=='M'?0:1); cnt++;
            pos=(r+l)/2;
            cout << pos << flush << endl;
            continue;
        }
        frag2=(s[0]=='M'?0:1);
        if((frag^frag2)^((pos-r)%2)){
            l=pos;
        }
        else {
            r=pos;
            frag=frag2;
        }
        pos=(r+l)/2;
        cout << pos << flush << endl;
    }
    cin >> s; 
    if(s[0]=='V') return 0;
    cout << l << flush << endl;
    cin >> s; 
    if(s[0]=='V') return 0;
    else {
        cout << r << flush << endl;
        cin >> s;
    }
    return 0;
}