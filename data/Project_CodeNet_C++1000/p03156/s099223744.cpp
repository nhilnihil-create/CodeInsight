#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main() {
    ll N,A,B;
    cin>>N>>A>>B;
    vector<ll> P(N),a,b,c;
    rep0(i,N){cin>>P[i];}
    rep0(i,N){
        if(P[i]<=A){a.push_back(P[i]);}
        else if(P[i]>A&&P[i]<=B){b.push_back(P[i]);}
        else{c.push_back(P[i]);}
        
    }
    cout<<min(a.size(),min(b.size(),c.size()))<<endl;
}
