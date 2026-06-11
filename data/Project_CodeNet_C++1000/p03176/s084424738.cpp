#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <tuple>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

using ll=long long;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vll> vl2d;
typedef vector <vi> vi2d;
typedef vector <char> vc;
typedef vector <bool> vb;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <char,int> mci;
typedef map <int,int> mii;
typedef map <long,long> ml;
typedef map <string,string> mss;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define foreach(x,arr) for(auto& x:arr)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000LL
#define MOD 1000000007
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<"\n"; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define forch(ch,str) for(char& c : str)
#define FILL(a,b) memset(a,b,sizeof(a))
//Swift related stuff
#define append push_back
#define nil nullptr
#define guard(_condition) if (bool(_condition)){}
#define count size()
#define let const auto
#define var auto
#define startsWith(str) rfind(str, 0)
#define prq priority_queue
#define tostr(argument) to_string(argument)
#define alphabet "abcdefghijklmnopqrstuvwxyz"




void join(const vector<string>& v, char c, string& s) {

   s.clear();

   for (vector<string>::const_iterator p = v.begin();
        p != v.end(); ++p) {
      s += *p;
      if (p != v.end() - 1)
        s += c;
   }
}

typedef ll (* SegmentTreeFunc)(ll,ll);

class SegmentTree {
private:
    vll arr, tree;
    ll fullLastLevel;
    SegmentTreeFunc func;
    
    void build(ll from, ll low, ll high) {
        guard(low != high) else {
            guard(low < arr.count) else {
                return;
            }
            tree[from] = arr[low];
            return;
        }
        let mid = (low+high)/2;
        build(2 * from + 1, low, mid);
        build(2 * from + 2, mid+1, high);
        tree[from] = func(tree[2 * from + 1], tree[2 * from + 2]);
    }
    
    void update(ll node, ll low, ll high, ll idx, ll val) {
        guard(low != high) else {
            guard(low < arr.count) else {
                return;
            }
            /*
             what is called in arr as `idx` will be `node` in tree
             arr[low] = tree[node]
             */
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        let mid  = (low+high)/2;
        if (idx <= mid) {
            update(2 * node + 1, low, mid, idx, val);
        } else {
            update(2 * node + 2, mid+1, high, idx, val);
        }
        tree[node] = func(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    ll query(ll node, ll low, ll high, ll ql, ll qh) {
        if(qh < low || ql > high) {
            return 0;
        }
        if(ql <= low && qh >= high) {
            return tree[node];
        }
        let mid = (low+high)/2;
        let lr = query(node * 2 + 1, low, mid, ql, qh);
        let rr = query(node * 2 + 2, mid+1, high, ql, qh);
        return func(lr, rr);
    }
public:
    SegmentTree(vll arr,
                SegmentTreeFunc stf) {
        this->arr = arr;
        let cnt = arr.count;
        fullLastLevel = pow(2,ceil(log(cnt)/log(2)));
        tree.resize(fullLastLevel * 2 - 1, 0);
        func = stf;
        build(0, 0, fullLastLevel-1);
    }
    
    void update(ll elementPos, ll val) {
        update(0, 0, fullLastLevel-1, elementPos, val);
    }
    
    ll query(ll low, ll high) {
        return query(0, 0, fullLastLevel-1, low, high);
    }
};

ll getMax(ll a, ll b) {
    return a > b ? a : b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
    ll n;
    cin>>n;
    ll h[n], b[n];
    vll dp(n+1,0);
    rep(i,0,n) {
        cin>>h[i];
    }
    rep(i,0,n) {
        cin>>b[i];
    }
    
    
    ll res = 0;
    
    SegmentTree tree(dp, getMax);
    rep(flower, 0, n) {
        let mx = tree.query(0, h[flower]-1);
        dp[h[flower]] = mx + b[flower];
        tree.update(h[flower], dp[h[flower]]);
        res = MAX(res, dp[h[flower]]);
    }
    cout<<res<<endl;
    return 0;
}
