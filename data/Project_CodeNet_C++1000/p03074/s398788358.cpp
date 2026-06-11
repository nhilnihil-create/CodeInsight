#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, k;
string s;

int main(void){
    cin >> n >> k >> s;
    vector<lli> p;
    rep(i, n){
        if(i == 0) p.push_back(i);
        else{
            if(s[i] != s[i-1]) p.push_back(i);
        }
    }
    p.push_back(n);
    lli m = p.size();
    lli ans = 0;
    rep(i, m-1){
        if(s[p[i]] == '0'){
            ans=max(ans, p[min(i+2*k, m-1)]-p[i]);
        }else{
            ans=max(ans, p[min(i+2*k+1, m-1)]-p[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
