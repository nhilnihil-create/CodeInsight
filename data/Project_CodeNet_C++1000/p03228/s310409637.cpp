#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll a,b,k;
	cin >> a >> b >> k;
	ll T = a;
	ll A = b;
	int count = 0;
	while(count <= k-1){
		if(count % 2 == 0){
			if(T % 2 == 1){
				T -= 1;
				A += T/2;
				T /= 2;
			}else{
				A += T/2;
				T /= 2 ;
			}
		}else{
			if(A % 2 == 1){
				A -= 1;
				T += A/2;
				A /= 2;
			}else{
				T += A/2;
				A /= 2;
			}
		}
		count++;
	}
	
	cout << T << " " << A << endl;
    return 0;
}


