#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;
int D, G;
int p[maxn], c[maxn];
 
 
int solve(int mask) {
    int score = 0;
    int solved = 0;
    for (int i=0; i<D; i++) {
	if (mask>>i&1) {
	    solved += p[i];
	    score += (i+1)*100*p[i];
	    score += c[i];
	}
    }
 
    for (int i=D-1; i>=0 && score<G; i--) {
	if (mask>>i&1) continue;
	for (int j=0; j<p[i] && score<G; j++) {
	    solved++;
	    score+=(i+1)*100;
	}
	score+=c[i];
    }
 
    return solved;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
 
    cin>>D>>G;
    for (int i=0; i<D; i++) {
	cin>>p[i]>>c[i];
    }
 
 
    int res = 1e9;
    for (int mask=0; mask<(1<<D); mask++) {
	res = min(res, solve(mask));
    }
 
 
    cout<<res<<endl;
    return 0 ;
}

 
