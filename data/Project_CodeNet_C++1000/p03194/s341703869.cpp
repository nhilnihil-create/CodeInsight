#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
#include <array>
#include <numeric>
#include <regex>
#include <bitset>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> p_ii;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

ll prime[1000000];
bool is_prime[1000001];

ll sieve(ll n){
	int p = 0;
	for(int i=0;i<=n;i++)is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i)is_prime[j]=false;
		}
	}
	return p;
}



int main() {
    ll N, P;
    cin>>N>>P;

    ll cnt = sieve(1000000);

    if(N==1){
        cout<<P<<endl;
    }else{
        ll ans = 1;
        for (int i = 0; i < cnt; i++) {
            ll t = P, tc = 0;
            while(t!=0&&t%prime[i]==0){
                tc++;
                t/=prime[i];
            }
            if(tc>=N){
                ll x = 1;
                for (int j = 0; j < (tc/N); j++) {
                    x*=prime[i];
                }
                ans*=x;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}