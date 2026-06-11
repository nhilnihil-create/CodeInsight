#include <bits/stdc++.h>
#define rep(i,n) for (int64_t i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    sort(btoe(p));
    cout<<p[n-1]-p[0]<<endl;
    return 0;
}