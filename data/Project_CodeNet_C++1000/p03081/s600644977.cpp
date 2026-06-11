#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

#define DEBUG(x) cout<<#x<<": "<<x<<endl

using namespace std;

int main(){

	long N, Q;
	string S;

	cin >> N >> Q;
	cin >> S;

	vector<tuple<char, int>> T;

	for( long long i = 0; i < Q; i++ ){
		char t, d;
		cin >> t >> d;
		T.push_back(make_tuple(t, d=='R'?1:-1));
	}

	long long L = -1;
	long long R = N;
	while(R-L>1){
		int M = (L+R)/2;
		int cur = M;
		bool ok = false;

		for(int i = 0; i < T.size(); i++){
			if(S[cur] == get<0>(T[i])) cur+= get<1>(T[i]);
			if(cur == N ) break;
			if(cur == -1) {
				ok = true;
				break;
			}
		}
		if(ok) L = M;
		else R = M;
	}
	int LL = L;

	L = -1; R = N;
	while(R-L>1){
		int M=(L+R)/2;
		int cur=M;
		bool ok = false;

		for(int i = 0; i < T.size(); i++){
			if(S[cur] == get<0>(T[i])) cur+= get<1>(T[i]);
			if(cur == -1 ) break;
			if(cur == N) {
				ok = true;
				break;
			}
		}
		if(ok) R=M;
		else L=M;
	}

	int RR = R;
	if(LL>=RR) cout<<0<<endl;
	else cout << RR-LL-1<<endl;

	return 0;
}
