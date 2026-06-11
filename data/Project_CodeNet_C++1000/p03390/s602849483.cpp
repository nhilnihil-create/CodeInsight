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
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

LL f(LL A, LL B){
	if(A==B){
		return 2*(A-1);
	}
	LL low=1,hi=1e9+1;
	while(low+1<hi){
		LL m=(low+hi)/2;
		if(m*m<A*B){
			low=m;
		}
		else{
			hi=m;
		}
	}
	//cerr << A << ", " << B << ": " << low << endl;
	if(low*(low+1)<A*B){
		return 2*low-1;
	}
	return 2*low-2;
}
int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		if(a>b){
			swap(a,b);
		}
		cout << f(a,b) << endl;
	}

	return 0;
}

