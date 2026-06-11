#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

long long shakutori(vector<long long> a, long long n) {
    long long res = 0;

    int right = 0, sum = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && (sum ^ a[right]) == (sum + a[right])) {
            sum += a[right];
            right++;
        }

        res += (right - left);

        if (right == left) right++;
        else {
            sum -= a[left];
        }
    }

    return res;
}

int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    cout<<shakutori(a, n)<<endl;
    return 0;
}
