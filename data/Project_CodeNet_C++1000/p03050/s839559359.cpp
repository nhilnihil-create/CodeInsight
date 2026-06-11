#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<lli> divisor(lli x){
    vector<lli> d;
    for(lli i = 1; i*i <= x; i++){
        if(x%i == 0){
            d.push_back(i);
            if(i != x/i) d.push_back(x/i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

lli n;

int main(void){
    cin >> n;
    auto d = divisor(n);
    lli ans = 0;
    for(auto i : d){
        lli m = i-1;
        if(0 <= n/i && n/i <= m-1){
            ans += m;
        }
    }
    cout << ans << endl;
    return 0;
}
