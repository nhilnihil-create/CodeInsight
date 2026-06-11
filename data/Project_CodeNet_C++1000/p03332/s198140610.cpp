#include <bits/stdc++.h>
//using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
//#define int long long

std::vector<long long> binomial_coefficient(long long N){
    const long long MOD = 998244353;
    std::vector<long long> fac;
    std::vector<long long> facIE;
    std::vector<long long> comb;
    for(int i=0;i<=N;i++){
        if(i==0){
            fac.push_back(1);
        }else{
            fac.push_back(i*fac[i-1]%MOD);
        }
    }
    for(int i=0;i<=N;i++){
        long long r=1,b=fac[i],e=MOD-2;
        while(e){
            if(e&1){
                r=(r*b)%MOD;
            }
            b=(b*b)%MOD;
            e >>=1;
        }
        facIE.push_back(r);
    }
    for(int i=0;i<=N;i++){
        long long r=fac[N];
        r = (r*facIE[i])%MOD;
        r = (r*facIE[N-i])%MOD;
        comb.push_back(r);
    }
    return comb;
}



signed main(void){
    long long N,A,B,K;
    std::cin >> N >> A >> B >> K;
    std::vector<long long> nC;
    nC = binomial_coefficient(N);
    
    const long long MOD = 998244353;
    long long Ans=0;
    
    //REP(i,N+1){cout << nC[i] << " ";}cout << endl;
    
    REP(i,N+1){
        long long b=K-A*i;
        if(b>=0 && b%B==0 && b/B<=N){
            b/=B;
            Ans+=nC[i]*nC[b];
            Ans%=MOD;
        }
    }
    std::cout << Ans << std::endl;
    return 0;
}
