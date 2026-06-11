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

typedef long long LL;
using namespace std;

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

int main(int argc, char* argv[]){
	int N, X;
	vector<int> v;
	cin >> N >> X;

	for(int i=0; i<N; i++){
		int c;
		cin >> c;
		v.push_back(c);
	}
	v.push_back(X);

	sort(v.begin(), v.end());

	long long D = v[1] - v[0];
	for(int j=1; j<v.size(); j++){
		D = GCD(D, v[j] - v[j-1]);
	}
	cout << D << endl;
	return 0;
}