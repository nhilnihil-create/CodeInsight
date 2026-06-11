#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    vector<int> a(5);
    rep(i,5) cin >> a.at(i);
    vector<int> b(5);
    rep(i,5){
        b.at(i)=a.at(i)%10;
    }
    rep(i,5){
        if(b.at(i)==0)continue;
        else b.at(i)=10-b.at(i);
    }
    int m=0;
    rep(i,5){
        m=max(m,b.at(i));
    }
    int ans=0;
    rep(i,5){
        ans+=a.at(i)+b.at(i);
    }
    cout << ans-m << endl;
}