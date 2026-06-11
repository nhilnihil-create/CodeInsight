#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
long long INF = (1LL<<62);
typedef long long LL;

LL GCD(LL x, LL y){
    LL r=0;
	if( x<y ) swap(x, y);
    r = x % y;
    while(r!=0){
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

LL LCM(LL x, LL y){
	if( x<y ) swap(x, y);
    return (x/GCD(x, y))*y;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, M;
	string S, T;
	cin >> N >> M;
	cin >> S;
	cin >> T;

	LL ans = -1;
	if(S[0] != T[0]){
		printf("-1\n");
	}
	else{
		LL lcm = LCM(N, M);
		LL a = lcm / N;
		LL b = lcm / M;
		LL c = LCM(a, b);
		a = c/a;
		b = c/b;
		int no = 0;
		for(int i=0, j=0; i<S.size() && j < T.size(); i+=a, j+=b){
			if(S[i] != T[j]){
				no = 1;
				break;
			}
		}
		if(no == 1){
			printf("-1\n");
		}
		else{
			ans = lcm;
			printf("%lld\n", ans);
		}
	}
	return 0;
}

