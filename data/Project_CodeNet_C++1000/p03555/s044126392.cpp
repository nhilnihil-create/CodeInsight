#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    vector<string> c(2);
    rep(i,2) cin >> c[i];
    reverse(ALL(c[0]));
    if(c[0] == c[1]) cout << "YES" << endl;
    else cout << "NO" << endl;
}