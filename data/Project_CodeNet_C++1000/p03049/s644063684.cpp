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
vector<string> S;

LL ans = 0;
 
void solve(){
	LL B_start = 0;
	LL A_end = 0;
	LL B_start_A_end = 0;

	for(int i=0;i<N;i++){
		for(int j=0;j<S[i].size()-1;j++){
			if(S[i][j]=='A' && S[i][j+1]=='B') ans++;
		}
		if(S[i][0]=='B' && S[i][S[i].size()-1]=='A') B_start_A_end++;
		else if(S[i][0]=='B') B_start++;
		else if(S[i][S[i].size()-1]=='A') A_end++;
	}

	if(A_end==0 && B_start==0){
		ans += (max(0LL,B_start_A_end-1));
	}
	else if((A_end>0 && B_start==0) || (A_end==0 && B_start>0)){
		ans += B_start_A_end;
	}
	else if(A_end>0 && B_start>0){
		ans += min(A_end,B_start);
		ans += B_start_A_end;
	}
}
 
int main(){
    cin >> N;
    S = vector<string>(N);
    for(int i=0;i<N;i++) cin >> S[i];
 
    solve();
 
    cout << ans << endl;
    return 0;
}