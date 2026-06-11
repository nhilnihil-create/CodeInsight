#include <bits/stdc++.h>
#define REV(v) reverse(v.begin(), v.end());
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, start, stop) for (int i = start; i < stop; i++)
#define FORR(i, start, stop) for (int i = start; i > stop; i--)
#define SORT(v, n) sort(v, v + n);
#define SORTR(v, n) sort(v, v + n,greater<int>());
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.begin(), v.end(),greater<int>());
#define REMOVE(v,n) remove(vector<int> v,v+v.size(),int n)
#define ll long long
#define ull unsigned long long
#define pb(a) push_back(a)
#define INF 999999999
#define V(v,i,j) vector(v.begin() + i, v.begin() + j)
#define INSERT(va,vb) va.insert(va.end(), vb.begin(), vb.end())
using namespace std;
typedef vector<int> vint;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
const ll MOD = 1000000007;
void chmin(int &a, int b) { if (a > b) a = b; }

//vector< vector<int> > v (size1, vector<int>(size2) );

//累乗 a**n%mod
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin>>S;
    ll s=S.size();
    vector<ll> A(s),C(s),Q(s);

    if(S[0]=='A') A[0]=1;
    else A[0]=0;
    FOR(i,1,s){
        if(S[i]=='A') A[i]=A[i-1]+1;
        else A[i]=A[i-1];
    }

    if(S[0]=='C') C[0]=1;
    else C[0]=0;
    FOR(i,1,s){
        if(S[i]=='C') C[i]=C[i-1]+1;
        else C[i]=C[i-1];
    }

    if(S[0]=='?') Q[0]=1;
    else Q[0]=0;
    FOR(i,1,s){
        if(S[i]=='?') Q[i]=Q[i-1]+1;
        else Q[i]=Q[i-1];
    }

    ll ans=0;
    ll q;

    FOR(i,0,s){
        if(S[i]=='B' || S[i]=='?'){
            q=Q[s-1];
            if(S[i]=='?') --q;
            //cout<<q<<endl;
            if(i==0){
                continue;
            }else{
                ans+=(A[i-1]%MOD)*((C[s-1]-C[i])%MOD)*modpow(3,q,MOD)%MOD;
                ans%=MOD;
                //cout<<ans<<'a'<<endl;
                ans+=(A[i-1]%MOD)*((Q[s-1]-Q[i])%MOD)*modpow(3,q-1,MOD)%MOD;
                ans%=MOD;
                //cout<<ans<<'b'<<endl;
                ans+=(Q[i-1]%MOD)*((C[s-1]-C[i])%MOD)*modpow(3,q-1,MOD)%MOD;
                ans%=MOD;
                //cout<<ans<<'c'<<endl;
                ans+=(Q[i-1]%MOD)*((Q[s-1]-Q[i])%MOD)*modpow(3,q-2,MOD)%MOD;
                ans%=MOD;
                //cout<<ans<<endl;
            }
        }
    }

    cout<<ans%MOD<<endl;
    
}
//666