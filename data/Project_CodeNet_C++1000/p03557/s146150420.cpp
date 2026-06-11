#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

ll N;
ll A[100000];
ll B[100000];
ll C[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cin>>C[i];
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);

    vector<ll> ab(100005);
    rep(i,N){
        ll l=-1, r=N;
        while(r-l>1){
            ll m=(l+r)/2;
            if(B[i]<=A[m]) r=m;
            else l=m; 
        }
        ab[i]=r;
    }
    rep(i,N-1) ab[i+1]+=ab[i];
    //rep(i,N) cout<<ab[i]<<endl;

    ll ans=0;
    rep(i,N){
        ll l=-1, r=N;
        while(r-l>1){
            ll m=(l+r)/2;
            if(C[i]<=B[m]) r=m;
            else l=m; 
        }
        if(r>0) ans+=ab[r-1];
    }

    cout<<ans<<endl;
}