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

class B1DimensionalWorldsTale {
public:
	void solve(istream& in, ostream& out) {
        int n, m, X, Y; in >> n >> m >> X >> Y;
        vector<int> x(n), y(m);
        rep(i,n) in >> x[i];
        rep(i,m) in >> y[i];
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        bool ok = true;
        for(int z = X + 1;z <= Y;z++){
            if(x[n-1] < z && z <= y[0]){
                ok = false;
                out << "No War" << endl;
                break;
            }
        }
        if(ok) out << "War" << endl;
	}
};

int main() {
	B1DimensionalWorldsTale solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}