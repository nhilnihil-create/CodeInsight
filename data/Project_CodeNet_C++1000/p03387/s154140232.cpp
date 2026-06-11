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
    vector<int> p(3);
    rep(i,3) cin>>p[i];
    sort(etob(p));
    int dif=p[0]*2-p[1]-p[2];
    if(dif%2==0){
        cout<<dif/2<<endl;
    }else{
        cout<<dif/2+2<<endl;
    }

}