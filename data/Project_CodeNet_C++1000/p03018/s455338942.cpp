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

string S;

LL ans = 0;

void solve(){
	//"A"、"BC"のみで構成される部分列を探し、
	//その中で、各Aについて
	//自分よりも後ろにある"BC"の数を加算
	int BC_counter = 0;
	for(int i=S.size()-1;i>=0;){
		if(S[i]=='C' && i-1>=0){
			if(S[i-1]=='B'){
				BC_counter++;
				i -= 2;
			}else{
				i--;
				BC_counter = 0;
			}
		}else if(S[i]=='A'){
			ans += (BC_counter);
			i--;
		}else{
			i--;
			BC_counter = 0;
		}
	}
}
 
int main(){
    cin >> S;
 
    solve();

    cout << ans << endl;
    return 0;
}