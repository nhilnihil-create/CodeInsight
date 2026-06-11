#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n,k;
  	double ans = 0.0;
	cin >> n >> k;
  	if(n>=k) {
    	ans += (double)(n-k+1)/n;
    }
	rep(i, min(n, k-1)){
      	int kk = 0;
      	while(pow(2.0, kk)*(i+1)<k) kk++;
      	ans += pow(0.5, kk)/ n;
	}
	printf("%.9lf\n", ans);
}
