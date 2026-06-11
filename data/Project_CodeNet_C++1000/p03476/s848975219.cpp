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
    vector<int> primes(1e5+5,1);
    for(int i=3; i<1e5+5; ++i){
        for(int j=2; j*j<=i; ++j){
            if(i%j==0){
                primes[i]=j;
            }
        }
    }
    vector<int> candi(1e5+5,0);
    for(int i=3; i<1e5+5; ++i){
        candi[i]=candi[i-1];
        if(primes[i]==1){
            if(i%2==1 && primes[(i+1)/2]==1){
                candi[i]++;
            }
        }
    }
    int qqq; cin>>qqq;
    rep(qqqqq,qqq){
        int l,r; cin>>l>>r;
        cout<<candi[r]-candi[l-1]<<endl;
    }
    return 0;
}