#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int popcount(int n) {
    return __builtin_popcount(n);
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>init_a(n);
    rep(i,n) {
        cin >> a[i];
        init_a[i] = a[i];
    }
    sort(a.rbegin(),a.rend());
    int m1 = a[n/2-1];
    int m2 = a[n/2];
    a = init_a;
    rep(i,n) {
        if(m1>a[i]) cout << m1 << endl;
        else cout << m2 << endl;
    }
}