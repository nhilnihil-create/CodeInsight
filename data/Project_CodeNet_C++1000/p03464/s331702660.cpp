#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
int A[100010];
int K;
bool isOk(int num) {
    //cout << "***" << num << "***" << endl;
    rep(i, K) {
        num -= (num % A[i]);
        //cout << i << " " << num << endl;
    }
    return num >= 2;
}

bool isOk2(int num) {
    //cout << "***" << num << "***" << endl;
    rep(i, K) {
        num -= (num % A[i]);
        //cout << i << " " << num << endl;
    }
    return num > 2;
}

int isok_num(int num) {
    rep(i, K) {
        num -= (num % A[i]);
        //cout << i << " " << num << endl;
    }
    return num;
}

int binary_search1() {
    int ok = INF2;
    int ng = 1;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOk(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}
int binary_search2() {
    int ok = INF2;
    int ng = 1;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOk2(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> K;
    
    rep(i, K) cin >> A[i];
    int low = binary_search1();
    int high = binary_search2() - 1;
    if (isok_num(low) != 2) {
        cout << -1 << endl;
        return 0;
    }
    //cout << isok_num(low) << " " << isok_num(high) << endl;
    cout << low << " " << high << endl;

    return 0;
}
