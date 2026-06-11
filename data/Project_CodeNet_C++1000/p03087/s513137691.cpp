#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n,q;
    string s;
    cin >> n >> q >> s;
    vector<int> v(n+1);
    rep(i,n-1){
        string ss=s.substr(i,2);
        if(ss=="AC") v[i+1]++;
    }
    rep(i,n){
        v[i+1]+=v[i];
    }
    rep(i,q){
        int x,y;
        cin >> x >> y;
        x--;y--;
        cout << v[y]-v[x] << endl;
    }
}
