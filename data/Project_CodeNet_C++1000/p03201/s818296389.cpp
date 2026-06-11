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
#include <unordered_map> 
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
vector<LL> A;

LL ans = 0;

void solve(){
	sort(A.begin(),A.end());
	map<LL,int> remain;
	for(int i=0;i<N;i++){
		remain[A[i]]++;
	}
	for(int i=N-1;i>=0;i--){
		if(remain[A[i]]==0) continue;
		remain[A[i]]--;
		LL pow2 = 1;
		while(pow2<=A[i]) pow2 <<= 1;
		LL target_num = pow2 - A[i];
		if(remain.find(target_num)!=remain.end()){
			if(remain[target_num]==0) continue;
			ans++;
			remain[target_num]--;
		}
	}
}

int main(){
    cin >> N;
    A = vector<LL>(N);
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

	cout << ans << endl;
    return 0;
}