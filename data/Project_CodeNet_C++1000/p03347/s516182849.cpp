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
LL A[200000];

LL ans = 0;

void solve(){
	if(A[0]!=0){
		ans = -1;
		return;
	}
	for(int i=N-1;i>=1;i--){
		int seq_max = A[i];
		while(i>=1){
			if(A[i]==A[i-1]+1) i--;
			else break;
		}
		if(A[i]>A[i-1]+1){
			ans = -1;
			return;
		}
		ans += seq_max;
	}
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

    cout << ans << endl;
    return 0;
}