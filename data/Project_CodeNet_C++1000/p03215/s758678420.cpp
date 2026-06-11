#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N = in<ll>(),K = in<ll>();
    vector<ll> sum(N+1);
    sum[0] = 0;
    REP(i,N){
        sum[i+1] = sum[i] + in<ll>();
    }
    vector<ll> allsum;
    REP(i,N){
        for (size_t j = i+1; j < N+1; j++){
            allsum.push_back(sum[j] - sum[i]);
        }
    }
    ll answer = 0;
    for (int i = 59; i >= 0; i--){
        sort(ALL(allsum),greater<>());
        int count = 0;
        REP(l,allsum.size()){
            if(allsum[l] >> i == 1){
                count++;
            }else{
                break;
            }
        }
        bool oka = count >= K;
        if(oka){
            answer += 1LL << i;
        }
        REP(l,allsum.size()){
            if(allsum[l] >> i == 1){
                allsum[l] -= 1LL << i;
            }else if(oka){
                allsum[l] = 0;
            }else{
                break;
            }
        }
    }
    cout << answer << "\n";
}