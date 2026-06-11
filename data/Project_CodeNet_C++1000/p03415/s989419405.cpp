#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    vector<string> c(3);
    rep(i,3) cin >> c[i];
    cout << c[0][0] << c[1][1] << c[2][2] << endl;
}