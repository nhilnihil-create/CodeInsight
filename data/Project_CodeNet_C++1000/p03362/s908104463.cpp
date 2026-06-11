#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 1e9;
const int MOD = 1000000007;

struct Sieve {
        int n;
        vector<int> f,primes;
        
        Sieve(int n=1):n(n),f(n+1){
                f[0] = f[1] = -1;
                for(long long i=2;i<=n;++i){
                        if(f[i]) continue;
                        primes.push_back(i);
                        f[i] = i;
                        for(long long j = i*i;j <= n;j += i) {
                                if(!f[j]) f[j] = i;
                        }
                }
        }
        
        bool isPrime(int x){return f[x] == x;}
        
        vector<int> factorList(int x){
                vector<int> res;
                while(x != 1){
                        res.push_back(f[x]);
                        x /= f[x];
                }
                return res;
        }
        
        vector<pair<int,int>> factor(int x){
                vector<int> fl = factorList(x);
                if(fl.size() == 0) return {};
                vector<pair<int,int>> res(1,pair<int,int>(fl[0],0));
                for(int p:fl){
                        if(res.back().first == p){
                                res.back().second ++;
                        }else{
                                res.emplace_back(p,1);
                        }
                }
                return res;
        }
        
};

int main(){
        Sieve sieve(55560);
        int n ;
        cin >> n;
        int i = 0;
        vector<int> ans;
        while(ans.size() < n){
                if(sieve.isPrime(5*i+1)){
                        ans.push_back(5*i+1);
                }
                i++;
        }
        rep(j,n){
                cout << ans[j] << " "  ;
        }
        cout << endl;
}