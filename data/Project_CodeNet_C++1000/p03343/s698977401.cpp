#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int A[2001];
int main() {
	int N,K,Q;
	cin >> N >> K >> Q;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	int ret=1e9;
	vector<int> vs;
	vector<int> ws;
	for(int i=0;i<N;i++){
		vs.clear();
		ws.clear();
		for(int j=0;j<=N;j++){
			if(A[j]>=A[i]){
				ws.push_back(A[j]);
			}
			else{
				if(ws.size()>=K){
					sort(ws.begin(),ws.end());
					for(int k=0;k<ws.size()-K+1;k++){
						vs.push_back(ws[k]);
					}
				}
				ws.clear();
			}
		}
		if(vs.size()>=Q){
			sort(vs.begin(),vs.end());
			ret=min(ret,vs[Q-1]-vs[0]);
		}
	}
	cout << ret << endl;


	return 0;
}

