#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

template <typename T>
inline std::string to_bin_str(T n) {
    std::string str;
    while (n > 0) {
        str.push_back('0' + (n & 1));
        n >>= 1;
    }
    std::reverse(str.begin(), str.end());
    return str;
}

int main(){
    ll n; cin>>n;
    if(n==0){
        cout<< 0 <<endl;
        return 0;
    }
    bool sgn=(n>=0 ? true : false);
    n=abs(n);
    rep(i,0,50){
        if(i%2==0){
            if((n>>i)&1LL){
                if(!sgn) n+=(1LL<<(i+1));
            }
        }else{
            if((n>>i)&1LL){
                if(sgn) n+=(1LL<<(i+1));
            }
        }
    }
    cout<< to_bin_str(n) <<endl;

}