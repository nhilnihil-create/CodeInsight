#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define ALL(v) v.begin(),v.end()
#define mp make_pair
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it<<endl;}}
template <class X> void prrr(X test){int f=0;for(auto it:test){cout<<(f++!=0?" ":"")<<it;}cout<<endl;}
template<typename X>
istream&operator>>(istream&i,vector<X>&v){for(X&x:v)i>>x;return i;}

class UF { // union find from https://github.com/kartikkukreja/blog-codes (MIT)
    // [usage]
    // auto uf = new UF(n);
    // uf->merge(l, r); // 0 <= l, r <= n-1
    // ...
public:
    int *id; // inner id
    int cnt; // number of all vartices
    int *sz; // sz[i] means size of i's set
    UF(int N)   {
        cnt = N;
        id = new int[N];
        sz = new int[N];
        for(int i=0; i<N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF() {
        delete [] id;
        delete [] sz;
    }
    int find(int p) {
        int root = p;
        while (root != id[root]) root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    void merge(int x, int y) {
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        cnt--;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int count() {
        return cnt;
    }
};

// return sorted 約数list 1 <= x <= n
vector<ll> divv(ll n) {
  vector<ll> v;
  for(ll i = 1; i*i <= n; i++) {
    if(n%i == 0) {
      v.push_back(i);
      if(i*i != n) v.push_back(n/i);
    }
  }
  sort(ALL(v));
  return v;
}


int main() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    cin>>v;
    ll sum = 0;
    map<ll,ll> m;
    for(auto it:v){
        m[it]+=1;
    }
    for(auto it = m.rbegin();it!=m.rend();){
        if ((*it).second ==0) {
            it++;
            continue;
        }
        auto val = (*it).first;
        m[val]--;
        ll b = 1;
        while(b<=val) b*=2;
        auto x = b -val;
        if(m.count(x) > 0 && m[x] > 0){
            sum++;
            m[x]--;
        }
    }
    pr(sum);
}