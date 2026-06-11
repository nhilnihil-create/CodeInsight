#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};

class B754 {
public:
	void solve(istream& in, ostream& out) {
        string s; in >> s;
        int n = s.size();
        int ans = 1e6;
        for(int i = 0; i < n - 2; i++){
            int a = ((int)s[i] - 48) * 100 + ((int)s[i+1] - 48) * 10 + (int)s[i+2] - 48;
            ans = min(ans, abs(a-753));
        }
        out << ans << endl;
	}
};

int main() {
	B754 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}