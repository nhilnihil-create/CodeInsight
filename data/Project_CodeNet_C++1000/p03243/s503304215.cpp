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

class BAtCoderBeginnerContest111 {
public:
	void solve(istream& in, ostream& out) {
        int n; in >> n;
        for(int i = n;i <= 999;i++){
            int I = i;
            int a = I / 100;
            I %= 100;
            int b = I / 10;
            I %= 10;
            int c = I;
            if(a == b && b == c) {
                out << a << b << c << endl;
                break;
            }

        }
	}
};

int main() {
	BAtCoderBeginnerContest111 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}