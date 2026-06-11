#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll A=n/100;
	bool a=false;
	if(A<=12&&A>=1){
		a=true;
	}
	ll B=n%100;
	bool b=false;
	if(B<=12&&B>=1){
		b=true;
	}
	if(a){
		if(b){
			cout <<"AMBIGUOUS";
		}
		else{
			cout << "MMYY";
		}
	}
	if(a!=true){
		if(b){
			cout << "YYMM";
		}
		else{
			cout << "NA";
		}
	}
	// your code goes here
	
	return 0;
}