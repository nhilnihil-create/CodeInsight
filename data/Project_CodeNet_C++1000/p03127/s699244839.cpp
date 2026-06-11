#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define DEBUG
#define PI 3.141592653589793238462643383279
 
#define _GLIBCXX_DEBUG
#ifdef DEBUG
#define s(...) show(__VA_ARGS__);
#define sl(...) show(__VA_ARGS__);cout<<endl;
#else
#define s(...)
#define sl(...)
#endif
void show() {}
template <class Head,class... Args>void show(Head t,Args... args){std::cout<<t<<" ";show(args...);}
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define REP1(i, n) for(ll i = 1; i <= n; i++)
#define REPR1(i, n) for(ll i = n; i >= 1; i--)
#define FOR1(i, m, n) for(ll i = m; i <= n; i++)
#define ALL(v) v.begin(), v.end()


ll t[100010];
ll h[100010];

ll root(ll x){
    if(t[x]==x){
        return x;
    }else{
        return t[x]=root(t[x]);
    }
}

int main(){
    ll N;
    cin>>N;
    
    vector<ll> H(N);
    
    REP(i,N){
        cin>>H[i];
    }
    
    ll cnt;
    while(true){
        cnt=0;
        sort(H.begin(),H.end());
        for(ll i=0;H[i]<=0;i++)cnt++;
        if(cnt>=N-1){
            break;
        }
        
        FOR(i,cnt+1,N){
            H[i]%=H[cnt];
        }
    }
    cout<<H[cnt];
    return 0;
    
    // REP(i,N){
    //     t[i]=i;//t.push_back(i);
    //     h[i]=0;//h.push_back(0);
    // }
    // REP(ttttt,Q){
    //     ll q;
    //     cin>>q;
    //     if(q==0){
    //         ll a,z;
    //         cin>>a>>z;
    //         ll mi=min(root(a),root(z));
    //         ll ma=max(root(a),root(z));
    //         if(a!=z){
    //             if(h[mi]==h[ma]){
    //                 t[ma]=mi;
    //                 h[mi]++;
    //             }else if(h[mi]>h[ma]){
    //                 t[ma]=mi;
    //             }else{
    //                 t[mi]=ma;
    //             }
    //         }
    //     }else{
    //         ll a,z;
    //         cin>>a>>z;
    //         cout<<(root(a)==root(z)?"Yes":"No")<<endl;
    //     }
    // }
    // REP(i,N){
    //     sl(i,":",t[i],h[i]);
    // }
    //cout<<fixed<<setprecision(32)<<m;
    //sort(ALL(C),[](auto& a, auto& b) {return a[2] < b[2];});
    //if(equal(D.begin(), D.end()-1, K.begin()))cout<<"Yes";else cout<<"No";
    cout<<endl;
    return 0;
}
