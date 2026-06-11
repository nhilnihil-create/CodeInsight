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

int main() {
	int N;
	cin >> N;
	LL sum=0;
	LL m=1LL<<60;
	for(int i=0;i<N;i++){
		LL a,b;
		cin >> a >> b;
		sum+=b;
		if(a>b){
			m=min(m,b);
		}
	}
	cout << max(sum-m,0LL) << endl;

	return 0;
}

