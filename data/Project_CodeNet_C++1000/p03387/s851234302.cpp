#include <iostream>
#include <algorithm> 
#include <cmath>
//#include <bitset>
//#include <deque>
#include <iterator>
#include <map> 
//#include <queue>
//#include <stack>
#include <string>
#include <vector>
#include <array>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 



int main() {
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(),v.end());
	v[0] += v[2] - v[1];
	int d = v[2] - v[1] + (v[2] - v[0])/ 2;
	if ((v[2] - v[0]) % 2 != 0) {
		d += 2;
	}  
	cout << d;
}










