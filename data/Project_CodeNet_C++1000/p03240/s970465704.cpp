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
    vector<int> ans(3);
    vector<int> x(n), y(n), h(n);
    rep(i,n) cin>>x[i]>>y[i]>>h[i];
    for(int i=0; i<=100; ++i){
        for(int j=0; j<=100; ++j){
            bool ok=true;
            int hi;
            rep(K,n){
                if(h[K]>0){
                    hi=h[K]+abs(i-x[K])+abs(j-y[K]);
                    break;
                }
            }
            rep(K,n){
                if(h[K]!=max(0,(hi-abs(i-x[K])-abs(j-y[K])))) ok=false;
            }
            if(ok && hi>0){
                ans[0]=i; ans[1]=j; ans[2]=hi;
            }
        }
    }
    rep(i,3) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}