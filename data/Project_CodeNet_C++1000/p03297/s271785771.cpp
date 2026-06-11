#include<bits/stdc++.h>
using namespace std;

int main(){
	#define int long long
	int T , A , B , C , D;
	for(cin >> T ; T ; --T){
		cin >> A >> B >> C >> D;
		if(A < B || B > D){puts("No"); continue;}
		A %= B; D = __gcd(D , B);
		int tms = (B - 1 - A) / D; A += tms * D;
		puts(C >= A ? "Yes" : "No"); continue;
	}
	
	return 0;
}
