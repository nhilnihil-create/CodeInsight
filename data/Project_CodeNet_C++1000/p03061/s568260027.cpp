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

long long A[100002] = {0};

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for(int i=1; i<=N; i++){ cin >> A[i]; }

	if(N == 2){
		cout << max(A[1], A[2]) << endl;
		return 0;
	}

	long long d = A[1];
	vector<int> v;
	v.push_back(1);
	for(int i=2; i<=N; i++){
		long long u = GCD(d, A[i]);
		if(u < d){
			d = u;
			v.push_back(i);
		}
	}
    long long ans = 1;
	for(int k=0; k<v.size(); k++){
		long long d = 1;
		int index = v[k];
		int count = 0;
		for(int i=1; i<=N; i++){
			if(i == index) continue;
			count++;
			if(count == 1){
				d = A[i];
			}
			long long u = GCD(d, A[i]);
			if(count > 1) d = u;
		}
		if(ans < d) ans = d;
	}
	cout << ans << endl;
	return 0;
}