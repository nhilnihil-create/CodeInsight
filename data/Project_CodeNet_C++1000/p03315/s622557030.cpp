#include <bits/stdc++.h> 
using namespace std;
 
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

#define PI 3.14159265359  
const long long INF = 1LL << 60;
long long MOD = 1000000007;


long long lcm (int a, int b){return  (long long) a*b /gcd(a,b);}
long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long dp[200100];

vector<pair<long long, long long> > prime_factorize(long long N){
    vector<pair< long long , long long> > res;
    for(long long a = 2; a* a <= N; a++){
        if(N%a != 0)continue;
        long long ex = 0;
        while(N%a == 0){
            ex++;
            N /= a;
        }

        res.push_back({a,ex});
    }

    if(N!=1)res.push_back({N,1});
    return res;
    
}


int main(){
    string S;
    cin >> S;

    int a = 0;
    rep(i,4){
        if(S[i] == '+')a ++;
        else a--;
    }
    cout << a << endl;




}



