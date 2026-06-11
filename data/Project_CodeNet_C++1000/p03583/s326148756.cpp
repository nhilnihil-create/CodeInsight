#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>
#include <bitset>

using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define reppe(i,a,b) for(int i = (int)(a) ; i <= (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repme(i,a,b) for(int i = (int)(a) ; i >= (int)(b) ; --i)

typedef long long ll;

long long gcd(long long a,long long b){if(b==0)return a;return gcd(b,a%b);}
long long lcm(long long a,long long b){return a*b/gcd(a,b);}
int mod_pow(long long a,long long n,long long p){if(n == 1){return a%p;}if(n%2==1){return(a*mod_pow(a,n-1,p))%p;}long long t=mod_pow(a,n/2,p);return (t*t)%p;}
long long mod(long long v,long long p){long long res=v%p;if(res<0){res+=p;}return res;}

template < typename T > void coutVector(vector<T> v){for(int i=0;i<int(v.size());++i){if(i>0)cout<<" "<<v[i];else cout<<v[i];}cout<<endl;}
template < typename T > void coutVectorWithEndl(vector<T> v){for(int i=0;i<int(v.size());++i){cout<<v[i]<<endl;}}
template < typename T > vector<T> cinVector(int n) {vector<T> res(n);for(int i=0;i<n;++i){cin>>res[i];}return res;}
const int MAX = 510000;
const ll MOD = 1e9+7;

/*
                       4 / N = 1 / i + 1 / j + 1 / k
               4 * i * j * k = j * k * N + k * i * N + i * j * N
k(4 * i * j - j * N - i * N) = i * j * N
                           k = i * j * N / (4 * i * j - j * N - i * N)
*/

int main() {
    int N; cin >> N;
    int maxAns = 3500;
    for (long long i = 1; i <= maxAns; ++i) {
        for (long long j = 1; j <= maxAns; ++j) {
            long long p = i * j * N;
            long long q = (4 * i * j - j * N - i * N);
            if (q <= 0 || p % q != 0) continue;
            long long k = p / q;
            cout << i << " " << j << " " << k;
            return 0;
        }
    }
}
