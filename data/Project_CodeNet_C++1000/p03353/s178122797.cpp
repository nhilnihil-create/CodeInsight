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
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};

class CKThSubstring {
public:
	void solve(istream& in, ostream& out) {
        string s; int k;
        in >> s >> k;
        int sz = s.size();
        vector<string> a;
        int cnt = 0,z = 0;
        rep(i,k){
            int j = 0;
            while(j < sz - i){
                string sub = s.substr(j,i+1);
                a.push_back(sub);
                j++;
                cnt++;
            }
        }
        sort(a.begin(),a.end());
        rep(i,cnt - 1) {
            if (a[i + 1] == a[i]){
                a[i] = "00";
                z++;
            }
        }
        sort(a.begin(),a.end());

        out << a[z + k-1] << endl;
	}
};

int main() {
	CKThSubstring solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}