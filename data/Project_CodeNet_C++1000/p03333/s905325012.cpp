#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int L[100001],R[100001];
int main(){
    int n;
    cin>>n;
    int l,r;
    rep(i,n){
        cin>>l>>r;
        L[i]=l;
        R[i]=r;
    }
    sort(L,L+n,greater<int>());
    sort(R,R+n);
    ll mx=0;
    ll sum=0;
    rep(i,n){
        mx=max(mx,sum+max(L[i],-R[i]));
        sum+=L[i]-R[i];
        mx=max(mx,sum);
    }
    cout<<mx*2<<endl;
    return 0;
}