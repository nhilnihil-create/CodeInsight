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

bitset<2000*1000+1> bs;
int main() {
	int N;
	cin >> N;
	int sum=0;
	bs[0]=1;
	for(int i=0;i<N;i++){
		int a;
		cin >> a;
		sum+=a;
		bs|=(bs<<a);
	}
	for(int i=sum/2;i>=0;i--){
		if(bs[i]){
			cout << sum-i << endl;
			break;
		}
	}

	return 0;
}

