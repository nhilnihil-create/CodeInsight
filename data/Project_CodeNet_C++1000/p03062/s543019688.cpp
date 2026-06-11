#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0;
    int cnt = 0;
    bool ok = false;
    ll minv = 1001001001;
    rep(i,n) {
        cin >> a[i];
        sum += abs(a[i]);
        if(a[i] < 0) cnt++;
        if(a[i] == 0) ok = true;
        minv = min(minv,abs(a[i]));
    }
    if(ok || cnt%2==0) {
        cout << sum << endl;
        return 0;
    } else {
        sum -= 2*abs(minv);
        cout << sum << endl;
    }

}