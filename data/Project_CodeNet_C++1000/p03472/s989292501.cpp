#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,h; cin>>n>>h;
    vector<int> a(n), b(n);
    rep(i,n) cin>>a[i]>>b[i];
    sort(etob(a));
    int m=a[0];
    sort(etob(b));
    int cnt=n;
    rep(i,n){
        if(m>=b[i]){
            cnt=i;
            break;
        }
    }
    int ans=0;
    rep(i,cnt){
        ans++;
        h-=b[i];
        if(h<=0){
            cout<<ans<<endl;
            return 0;
        }
    }
    ans+=(h+m-1)/m;
    cout<<ans<<endl;
    return 0;
}