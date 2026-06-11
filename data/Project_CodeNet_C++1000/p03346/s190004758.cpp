#include <bits/stdc++.h>
#include <bitset>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N;
    vec id(N);
    rep(i,N){
        cin>>A;
        --A;
        id[A] = i;
    }
    ll len = 0, temp = 0;
    reps(i,1,N){
        if(id[i] > id[i-1]){
            ++temp;
        }else{
            len = max(len, temp);
            temp = 0;
        }
    }
    cout<<N - max(len, temp) - 1<<endl;
}