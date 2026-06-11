#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


void positive(int N) {
    stack<int> st;

    int x = N;
    st.push(x % 2);
    x /= 2;
    while (x) {
        int r = x % 4;
        x /= 4;
        switch (r) {
            case 0: st.push(0); st.push(0); break;
            case 1: st.push(1); st.push(1); break;
            case 2: st.push(0); st.push(1); break;
            case 3: st.push(1); st.push(0); x += 1; break;
        }
    }

    while (st.top() == 0) st.pop();

    while (!st.empty()) {
        cout << st.top(); st.pop();
    }
    cout << endl;
}

void negative(int N) {
    stack<int> st;

    int x = -N;
    while (x) {
        int r = x % 4;
        x /= 4;
        switch (r) {
            case 0: st.push(0); st.push(0); break;
            case 1: st.push(1); st.push(1); break;
            case 2: st.push(0); st.push(1); break;
            case 3: st.push(1); st.push(0); x += 1; break;
        }
    }

    while (st.top() == 0) st.pop();

    while (!st.empty()) {
        cout << st.top(); st.pop();
    }
    cout << endl;
}

int main() {
    int N; cin >> N;
    if (N == 0) {
        cout << '0' << endl;
    } else if (N > 0) {
        positive(N);
    } else {
        negative(N);
    }
    return 0;
}
