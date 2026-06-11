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
    map<int,int> fmp, smp;
    rep(i,n){
        if(i%2==0) fmp[p[i]]++;
        else smp[p[i]]++;
    }
    int a=0, b=0,checka, checkb;
    for(auto& v :fmp){
        if(a<v.second){
            a=v.second;
            checka=v.first;
        }
    }
    for(auto& v : smp){
        if(b<v.second){
            b=v.second;
            checkb=v.first;
        }
    }
    if(checka!=checkb){
        cout<<n-a-b<<endl;
        return 0;
    }
    int c=0,d=0;
    for(auto& v: fmp){
        if(v.first==checka) continue;
        c=max(c,v.second);
    }
    for(auto& v: smp){
        if(v.first==checkb) continue;
        d=max(d,v.second);
    }
    int an=max(a+d, c+b);
    cout<<n-an<<endl;
    return 0;
}