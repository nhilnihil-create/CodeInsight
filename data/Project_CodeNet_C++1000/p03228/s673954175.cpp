#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;

int main() {
    vector<int> a(2);
    cin >> a[0] >> a[1];
    int k;
    cin >> k;
    int now = 0;
    rep(i,k) {
        int n = a[now];
        if(n%2 == 1) a[now]--;
        a[1-now] += a[now]/2;
        a[now] /= 2;
        now = 1-now;
    }
    cout << a[0] << " " << a[1] << endl;
}