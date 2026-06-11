#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b){
   return a * b / gcd(a, b);
}

int main(){
	int a,b,k;
	cin >> a >> b >> k;
	int cnt = 0;
	int ans = 1;
	for(int i = lcm(a,b);i >= 1;i--){
		if(a%i == 0 && b%i == 0){
			cnt++;
		}
		if(cnt == k){
			cout << i << endl;
			return 0;
		}
	}
}