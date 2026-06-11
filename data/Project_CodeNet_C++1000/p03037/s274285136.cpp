#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> l(m);
    vector<int> r(m);
    rep(i,m) cin >> l.at(i) >> r.at(i);
    vector<int> a(n+1);
    rep(i,m){
        a.at(0)++;
        a.at(l.at(i)-1)--;
        a.at(r.at(i))++;
        a.at(n)--;
    }
    vector<int> b(n+1);
    int sum=0;
    rep(i,n){
        sum+=a.at(i);
        b.at(i)=sum;
    }
    int ans=0;
    rep(i,n){
        if(b.at(i)==0)ans++;
    }
    cout << ans << endl;
}
