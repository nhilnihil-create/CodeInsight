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
LL A[10000],B[10000];

string ans = "Yes";

void solve(){
	for(int i=0;i<N;i++){
		if((B[i]-A[i])%2==1 && A[i]<B[i]){
			A[i]+=2;B[i]++;
		}
	}
	LL pos = 0,neg = 0;
	for(int i=0;i<N;i++){
		if(B[i]-A[i]>0) pos += (B[i]-A[i])/2;
		if(B[i]-A[i]<0) neg -= (B[i]-A[i]);
	}
	if(pos<neg) ans = "No";
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];
 
    solve();

    cout << ans << endl;
    return 0;
}