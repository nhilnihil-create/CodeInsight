#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n;
    cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    int m=0,sum=0;
    rep(i,n){
        m=max(m,p[i]);
        sum+=p[i];
    }
    cout<<sum-m/2<<endl;
}