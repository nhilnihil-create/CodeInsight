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

class AAtCoderBeginnerContest999 {
public:
	void solve(istream& in, ostream& out) {
        string n; in >> n;
        rep(i,3){
            if(n[i] == '1') out << 9;
            else out << 1;
        }
	}
};

int main() {
	AAtCoderBeginnerContest999 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}