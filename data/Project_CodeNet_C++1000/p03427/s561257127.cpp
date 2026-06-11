#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    string N;
    cin >> N;
    int count = 0;
    rep(i, 0, N.size()){
        if(N[i] == '9') count++;
    }
    ll ans;
    if(count == N.size()-1 && N[0] != '9'){
        ans = (N[0] - '0') + 9 * (N.size()-1);
        cout << ans << endl;
        return 0;
    } 
    if(count == N.size()){
        ans = 9 * (N.size());
        cout << ans << endl;
        return 0;
    }
    ans = ((N[0] - '0')-1) + 9 * (N.size()-1);
    cout << ans << endl;
}

