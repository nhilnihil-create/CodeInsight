#include <bits/stdc++.h>
using namespace std;
//#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

class binomial{
    private:
    const long long MOD = 998244353;
    std::vector<long long> fac;
    std::vector<long long> facIE;
    
    long long inv(int b){
        long long r=1,e=MOD-2;
        while(e){
            if(e&1){
                r=(r*b)%MOD;
            }
            b=(b*b)%MOD;
            e >>=1;
        }
        return r;
    }
    
    public:
    void precalc(long long N){
        fac.resize(N+1);
        facIE.resize(N+1);
        fac[0]=1;
        for(long long i=0;i<N;i++){
            fac[i+1]=((i+1)*fac[i])%MOD;
        }
        
        facIE[N] = inv(fac[N]);
        for(int i=N-1;i>=0;i--){
            facIE[i]=((i+1)*facIE[i+1])%MOD;
        }
    }
    
    long long get(long long n,long long r){
        if(r<0 || n<r)return 0;
        long long R = fac[n];
        R = (R*facIE[r])%MOD;
        R = (R*facIE[n-r])%MOD;
        return R;
    }
    
};
 
 
signed main(void){
    long long N,A,B,K;
    std::cin >> N >> A >> B >> K;
    
    const long long MOD = 998244353;
    long long Ans=0;
    
    binomial binom;
    binom.precalc(N);
    
    REP(i,N+1){
        long long b=K-A*i;
        if(b>=0 && b%B==0 && b/B<=N){
            b/=B;
            Ans+=(binom.get(N,i)*binom.get(N,b))%MOD;
            Ans%=MOD;
        }
    }
    std::cout << Ans << std::endl;
    return 0;
}

