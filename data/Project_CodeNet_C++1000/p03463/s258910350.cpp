#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n,a,b;cin >> n >> a >> b;
    if((b-a)%2 == 1){
        cout << "Borys"<< endl;
    }
    else cout << "Alice" << endl;
    return 0;
}