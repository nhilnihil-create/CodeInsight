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

class AHEX {
public:
	void solve(istream& in, ostream& out) {
        char x, y; in >> x >> y;
        map<char,int> mp; //={('A',1),('B',2),('C',3),('D',4),('E',5),('F',6)};
        mp.insert(make_pair('A',1));
        mp.insert(make_pair('B',2));
        mp.insert(make_pair('C',3));
        mp.insert(make_pair('D',4));
        mp.insert(make_pair('E',5));
        mp.insert(make_pair('F',6));
        if(mp.at(x) > mp.at(y)) out << '>' << endl;
        else if(mp.at(x) < mp.at(y)) out << '<' << endl;
        else out << '=' << endl;
	}
};

int main() {
	AHEX solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}