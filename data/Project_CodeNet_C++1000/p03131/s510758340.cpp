#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	ll k,a,b;
	cin >> k >> a >> b;
	ll now = 1;
	int i=0;
	while(i<k){
		if(now<a) {
			now++;
			i++;
		}
		if(now>=a){
			if(b-a>2&&k-i>=2){
				now+=b-a;
				i+=2;
			}
			else{
				now++;
				i++;
			}
		}
	}
	cout << now << endl;
	return 0;
}
