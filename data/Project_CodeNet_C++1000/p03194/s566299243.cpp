#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = INF+7;
const ll LINF = 1e18;
#define rep(i,N) for(int (i)=0;(i)<(N);++(i))
#define rrep(i,N) for(int (i)=(N-1);(i)>0;--i)
#define FOR(i,j,N) for(int (i)=(j);(i)<(N);++(i))
#define put(n) cout<<(n)<<endl;
#define all(v) v.begin(),v.end()
#define MP make_pair
#define pb(n) push_back(n)
#define int long long 
#define cint boost::multiprecision::cpp_int

int N,P;

vector<int> Enumeration_diviser(int N){
    std::vector<int> diviser;
    for(int i=1;i*i<=N;++i){
        if(N % i == 0){
            diviser.emplace_back(i);
            diviser.emplace_back(N/i);
        }
    }
    return diviser;
}

cint POW(cint x,cint n){
    cint res = 1;
    while(n){
        if(n%2) res *= x;
        if(res > P){
            res = -1;
            break;
        }
        x *= x;
        n >>= 1; 
    }
    return res;
}

bool is_prime(int p){
    bool is_prime = true;
    for(int j=2;j*j<=p;++j){
        if(p % j == 0){
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

signed main(){
    cin >> N >> P;

    vector<int> d = Enumeration_diviser(P);
    sort(all(d));
    int ans = 1;

    if(is_prime(P)){
        cout << ans << endl;
        return 0;
    }

    for(int i=1;i<d.size();++i){
        if(POW(d[i],N) == -1) break;
        if(P % POW(d[i],N) == 0) ans = d[i];
    }

    cout << ans << endl;
    return 0;
}