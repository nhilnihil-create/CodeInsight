#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0 ; i < (int)(n) ; i++)
typedef long long ll;
////////////////////////////////////////////////
int main(){
    string s;
    int n;
    cin >> n >> s;
    int ans = 0;
    rep(i, n) {
        string x, y, t;
        int cnt = 0;
        t=s;
        y=t.substr(i);
        x=t.erase(i);
        rep(j,i){
            if (x.find(x.at(j))==j && y.find(x.at(j))!=-1) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans <<endl;

}