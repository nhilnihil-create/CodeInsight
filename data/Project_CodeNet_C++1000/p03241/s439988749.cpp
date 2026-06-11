#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,m;
    cin>>n>>m;
    vector<int> yaku;
    for(int i=1; i*i<=m; ++i){
        if(m%i==0){
            if(m==i*i) yaku.push_back(i);
            else{
                yaku.push_back(i); yaku.push_back(m/i);
            }
        }
    }
    sort(etob(yaku));
    int ans;
    for(auto& v: yaku){
        if(v>=n) ans=v;
        else break;
    }
    cout<<m/ans<<endl;
    return 0;
}