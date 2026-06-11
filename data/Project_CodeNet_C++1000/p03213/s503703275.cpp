#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define ll long long

ll calc(int n, std::vector<ll> cnt){
    ll ans=0;
    for(int i=2; i<cnt.size(); ++i){
        if(cnt[i] >= n-1) ++ans;
    }
    return ans;
}

int main(){
    int n; std::cin >> n;
    std::vector<ll> cnt(n+1,0);

    // count primes in n!
    for(int i=2; i<n+1; ++i){
        int cur=i;
        for(int j=2; j<i+1; ++j){
            while(cur % j == 0){
                ++cnt[j];
                cur /= j;
            }
        }
    }
    ll ans=0;
    ans += calc(75,cnt);
    ans += calc(25,cnt) * (calc(3,cnt)-1);
    ans += calc(15,cnt) * (calc(5,cnt)-1);
    ans += calc(5,cnt) * (calc(5,cnt)-1) * (calc(3,cnt)-2) / 2;

    std::cout << ans << std::endl;

    return 0;
}