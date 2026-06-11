#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

LL gcd(LL val1, LL val2);

int main(){
    int N;
    LL X;
    cin >> N >> X;
    vector<LL> x(N);
    REP(i,N)cin>>x[i];

    vector<LL> diff(N);
    REP(i,N){
        diff[i] = abs(x[i] - X);
    }

    set<LL> s(diff.begin(), diff.end());
    LL ans = diff[0];
    for(auto itr = s.begin(); itr!=s.end(); itr++){
        ans = gcd(ans, *itr);
    }
    cout << ans << endl;

    return 0;
}

LL gcd(LL min_val, LL max_val){
    LL r = max_val % min_val;
    if(r == 0){
        return min_val;
    }
    return gcd(r, min_val);
}