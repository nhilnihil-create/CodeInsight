#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if(n > m){
        ans += n;
        n--;
    }else{
        ans += m;
        m--;
    }
    if(n > m){
        ans += n;
    }else{
        ans += m;
    }
    cout << ans << endl;
    return 0;
}