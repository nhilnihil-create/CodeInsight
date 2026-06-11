#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> k(n);
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n){
        cin >> k.at(i);
        rep(j,k.at(i)) cin >> a.at(i).at(j);
    }
    vector<int>b(m,0);
    rep(i,n){
        rep(j,k.at(i)){
            b.at(a.at(i).at(j)-1)++;
        }
    }
    int count=0;
    rep(i,m){
        if(b.at(i)==n) count++;
    }
    cout << count << endl;
}
