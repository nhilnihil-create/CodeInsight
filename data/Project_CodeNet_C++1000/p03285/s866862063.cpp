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

class BCakesAndDonuts {
public:
	void solve(istream& in, ostream& out) {
        int n; in >> n;
        bool ok = true;
        for(int i = 0;i <= n / 7;i++){
            if((n - 7 * i) % 4 == 0){
                out << "Yes" << endl;
                ok = false;
                break;
            }
        }
        if(ok) out << "No" << endl;
	}
};

int main() {
	BCakesAndDonuts solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}