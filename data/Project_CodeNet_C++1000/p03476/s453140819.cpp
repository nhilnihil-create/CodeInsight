#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


vector<bool> Eratosthenes(ll N){
    vector<bool> is_prime(N+1);
    rep(i,N+1){
        is_prime[i] = true;
    }

    for(int i=2;i<sqrt(N);i++){
        if(is_prime[i]){
            for(int j=i*2; j<N; j+=i){
                is_prime[j] = false;
            }
        }
    }
    is_prime[1] = false;
    return is_prime;
}

int main(){
    int Q; cin >> Q;
    vector<bool> is_prime = Eratosthenes(100010);

    vector<int> sum(100010);
    int cnt = 0;
    for(int i=1;i<=100001;i++){
        if(i%2==1 && is_prime[i] && is_prime[(i+1)/2]) cnt++;
        sum[i] = cnt;
    }

    rep(i,Q){
        int l,r; cin >> l >> r;
        cout << sum[r] - sum[l-1]  << endl;
    }
}