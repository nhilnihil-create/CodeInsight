#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, m) cin >> b.at(i);
    int cnt = 0;

    rep(i, n){
        int a;
        int ans = c;
        rep(j, m){
            cin >> a;
            ans += a * b.at(j);
        }
        if(ans>0) cnt+=1;
    }
    cout << cnt << endl;
    return 0;
}