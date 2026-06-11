#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;
typedef long long int ll;
ll A[200000];
int N;
bool C(ll x){
    map<ll, int> m;
    rep(i,1,N){
        if(A[i]<=A[i-1]){
            m.erase(m.upper_bound(A[i]),m.end());
            if(m.find(A[i])==m.end()){
                m.insert(make_pair(A[i],1));
                if(x==1) return false;
            }
            else{
                m[A[i]]++;
                ll j=A[i];
                while(m[j]==x){
                    if(j==1) return false;
                    m[j]=0;
                    if(m.find(j-1)==m.end()) m.insert(make_pair(j-1,1));
                    else m[j-1]++;
                    j--;
                }
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(i,0,N) cin>>A[i];
    ll l=0, r=2*1e5;
    while(r-l>1){
        ll mid=(l+r)/2;
        if(C(mid)) r=mid;
        else l=mid;
    }
    cout<<r<<"\n";
}