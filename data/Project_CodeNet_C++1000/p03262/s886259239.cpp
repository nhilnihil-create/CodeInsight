#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int gcd(int x,int y){
    return x%y ?  gcd(y, x % y) : y ;
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}

int main() {

    int n,k;
    cin >> n >> k  ;
    int x[n];

    for(int i=0;i<n;i++) cin >> x[i] ;

    int ans = abs(x[0]-k);
    for(int i=1;i<n;i++){
        int diff = abs(x[i]-k);
        ans = gcd(ans,diff); 
    }

    cout << ans << endl ;

    return 0 ;
}