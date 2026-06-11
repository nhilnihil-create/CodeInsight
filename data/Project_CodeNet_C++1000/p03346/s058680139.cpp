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
LL P[200000];

LL ans = 0;

void solve(){
	vector<int> index_P(N+1);
	for(int i=0;i<N;i++) index_P[P[i]] = i;

	int max_seq = 1;
	int seq = 1;
	for(int i=1;i<=N-1;i++){
		if(index_P[i]<index_P[i+1]){
			seq++;
			if(i==N-1) max_seq = max(max_seq,seq);
		}
		else{
			max_seq = max(max_seq,seq);
			seq = 1;
		}
	}
	ans = N - max_seq;
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> P[i];
 
    solve();

    cout << ans << endl;
    return 0;
}