    #include "bits/stdc++.h"
    using namespace std;
    int a[200010], b[200010];
     
    int main(int argc, char const *argv[])
    {
    	int n;
    	scanf("%d", &n);
    	
    	long long P = 0, Q = 0;
    	long long X = 0, Y = 0;
    	int cnt = 0;
    	bool good = true;
    	for(int i = 1; i <= n; i++) {
    		scanf("%d %d", &a[i], &b[i]);
    		good &= (a[i] == b[i]);
    		if(a[i] <= b[i]) {
    			P += b[i] - a[i];
    			Q += a[i];
    		} else {
    			X += a[i] - b[i];
    			Y += b[i];
    			++cnt;
    		}
    	}
    	long long ans = 0;
    	if(good) {
    		printf("0\n");
    		exit(0);
    	}
    	ans += Q;
    	ans += P;
    	if(cnt == 1) printf("%lld\n", ans);
    	else {
    		ans += Y;
    		int opt = INT_MAX;
    		for(int i = 1; i <= n; i++) {
    			if(b[i] < a[i]) {
    				opt = min(opt, b[i]);
    			}
    		}
    		ans -= opt;
    		printf("%lld\n", ans);
    	}
    	return 0;
    }