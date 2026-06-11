#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;

ll n;
ll a[100010];
ll kaijo[100010];
ll inv[100010];

ll expo(ll x,ll power) {
	ll res = 1;
	ll k = power;
	ll y = x;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N*y%N) % N;
		k /= 2;
	}
	return res;
}

void init(){
   for(ll i=0;i<100010;i++){
       if(i==0){
           kaijo[0]=1;
           inv[0]=1;
       }
       else{
           kaijo[i]=(kaijo[i-1]*i)%N;
           inv[i] = expo(i,N-2);
       }
   } 
}

int main(void){
    cin>>n;
    ll ans = 0;
    init();
    for(ll i=2;i<=n;i++){
        inv[i] +=inv[i-1];
        inv[i] = inv[i]%N;
    }
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        ll tmp = (inv[i]+inv[n-i+1]-1+N)%N;
        ans = (ans+a[i]*tmp)%N;
    }
    cout<<(ans*kaijo[n])%N<<endl;
    return 0;

}
