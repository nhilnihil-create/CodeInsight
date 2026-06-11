#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector
#define pb push_back
#define pob pop_back
#define vi vt<int>
#define vvi vt<vi>
#define vii vt<ii>
#define vvii vt<vii>
typedef long long ll;
#define For(i,a,b) for(int i = a; i < b; i++)
#define foR(i,a,b) for(int i = a; i <= b; i++)
#define roF(i,a,b) for(int i = a - 1; i >= b; i--)
#define Rof(i,a,b) for(int i = a; i >= b; i--)

int C[300001];
int mod = 998244353;

int binpow(int a, int b){
	if(b == 0){
		return 1;
	}
	if(b == 1){
		return a;
	}
	int temp = binpow(a,b>>1);
	if(b&1){
		return temp*temp%mod*a%mod;
	}else{
		return temp*temp%mod;
	}
}

signed main (){
	/*
	freopen(".inp","r",stdin);
	freopen(".out","w",stdout);
	*/
	int n, a, b, k, t = 0;
	cin >> n >> a >> b >> k;
	int allsum = 0;
	C[0] = 1;
	foR(i,1,n){
		C[i] = C[i-1]*(n-i+1)%mod*binpow(i,mod-2)%mod;
//		cout << binpow(i,mod-2)%mod << " ";
//		cout << C[i] << "\n";
	}
	foR(i,0,n){
		if((k-t)%b == 0 && (k-t)/b <= n){
//			cout <<"find " << i << " " << (k-t)/b << "\n";
//			cout << C[i] << " " << C[(k-t)/b] << " " << C[i]*C[(k-t)/b]%998244353 << "\n";
			allsum = (allsum + C[i]*C[(k-t)/b])%mod;
		}
		t += a;
		if(t > k){
			break;
		}
	}
	cout << allsum;
}

