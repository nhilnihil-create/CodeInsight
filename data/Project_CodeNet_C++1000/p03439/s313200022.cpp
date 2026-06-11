//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;

LL ans = 0;

string send_query(int i){
	cout << i << endl << flush;
	string s;
	cin >> s;
	return s;
}

void solve(){
	vector<string> seat(N,"none");
	int left = 0;
	int right = N;
	seat[0] = send_query(0);
	if(seat[0]=="Vacant") return;
	while(left+1<right){
		int center = (right+left)/2;
		seat[center] = send_query(center);
		if(seat[center]=="Vacant") return;
		if((center-left)%2==0){
			if(seat[left]==seat[center]) left = center;
			else right = center;
		}else{
			if(seat[left]!=seat[center]) left = center;
			else right = center;
		}
	}
}
 
int main(){
    cin >> N;
 
    solve();

    //cout << ans << endl;
    return 0;
}