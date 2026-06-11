#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n,m,c,temp,ans;
    cin >> n >> m >> c;
    vector<int> b(m),a(m);
    rep(i,0,m) cin >> b.at(i);
    ans = 0;
    rep(i,0,n){
        temp = c;
        rep(k,0,m){ 
            cin >> a.at(k);   
            temp += a.at(k)*b.at(k);
        }
        if(temp>0) ans++;

    }
    cout << ans << endl;
}