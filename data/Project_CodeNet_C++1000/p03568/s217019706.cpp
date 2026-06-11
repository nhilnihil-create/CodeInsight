#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

ll comb(ll a ,ll k){
    ll div=1;
    ll den=1;
    rep(i,k){
        div=div*(a-i);
        den=den*(k-i);
    }
    return div/den;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
vector<int>a(n);
rep(i,n)cin>>a[i];
int even_num=0,odd_num=0;
rep(i,n){
    if(a[i]%2==0){
        even_num++;
    }
    else{
        odd_num++;
    }
}
ll ans=0;
reps(i,even_num+1,1){
    ans+=comb(even_num,i)*pow(2,even_num-i)*pow(3,odd_num);
}
reps(i,odd_num+1,1){
    ans+=comb(odd_num,i)*pow(2,i)*pow(2,even_num);
}
cout<<ans<<endl;
return 0;
}