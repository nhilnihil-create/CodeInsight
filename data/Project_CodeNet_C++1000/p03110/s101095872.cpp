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
#define ll long long int
#include <iomanip>
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};

class BDigitalGifts {
public:
	void solve(istream& in, ostream& out) {
        int n; in >> n;
        vector<double> x(n);
        vector<string> u(n);
        rep(i,n) in >> x[i] >> u[i];

        double ans = 0;
        rep(i,n){
            if(u[i] == "JPY") ans += x[i];
            else ans += x[i] * 380000;
        }
        out << fixed << setprecision(10) << ans << endl;
	}
};

int main() {
	BDigitalGifts solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}