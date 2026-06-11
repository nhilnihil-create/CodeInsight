#include <bits/stdc++.h>
#define MAX_N 114514
#define ll long long int
using namespace std;
ll bit[MAX_N+2];
ll n;
ll a[MAX_N];
ll A[MAX_N];
ll N;
void init(ll n_){
    n=n_;
    for(ll i=0;i<n+1;i++){
        bit[i]=0;
    }

}
ll sum(ll i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x){
    while(i<=n){
        bit[i]+=x;
        i += i & -i;
    }
}
ll invnum(vector<ll> t){
    n=t.size();
    init(n);
    ll ans=0;
    for(ll j=0;j<n;j++){
        ans+=j-sum(t[j]);
        add(t[j],1);
    }
   return ans;
}

ll solve(ll x){
    vector<ll> S(N+1);
    vector<tuple<ll,ll>> U(N+1);
    S[0]=0;
    for(ll i=0;i<N;i++){
        if(A[i]<x){
            S[i+1]=S[i]-1;
        }
        else{
            S[i+1]=S[i]+1;   
        }
    }
    for(ll i=0;i<N+1;i++){
        U[i]=make_tuple(S[i],i+1);
    }
    sort(U.begin(),U.end());
    vector<ll> T(N+1);
    for(ll i=0;i<N+1;i++){
        T[i]=get<1>(U[i]);
    }
    return invnum(T);
}
int main(void){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    ll low=1;
    ll high=A[0];
    for(ll i=1;i<N;i++){
        if (high<A[i]){
            high=A[i];
        }
    }
    high++;
    ll M=(N*(N+1))/2;
    while(high-low>1){
        ll mid=(low+high)/2;
        if (solve(mid)*2<=M){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    cout<<low<<endl;
}
