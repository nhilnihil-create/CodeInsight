#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
long long lcm(long long a, long long b){
	if (b > a) swap(a, b);
	return a / gcd(a, b) * b;
}

int main(){
	
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++){
		long long A,B,C,D;
		cin>>A>>B>>C>>D;
		
		if(A<B||D<B){
			cout<<"No"<<endl;
			continue;
		}
		if(C>=B){
			cout<<"Yes"<<endl;
			continue;
		}
		
		long long G = gcd(B,D);
		
		A%=D,B%=D,C%=D;
		long long X = (D+C+1)%D,Y = (D+D+B-1)%D;
		
		if(X>Y){
			cout<<"Yes"<<endl;
			continue;
		}
		
		X = (X+D-A)%D,Y = (Y+D-A)%D;
		
		if(Y<X){
			cout<<"No"<<endl;
			continue;
		}
		X = (X+G-1)/G,Y = Y/G;
		
		//cout<<G<<','<<X<<','<<Y<<endl;
		if(X<=Y)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
		
	
	return 0;
}