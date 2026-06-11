#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
using namespace std;
typedef long long llint;
typedef long double ld;
#define inf 1e18

llint n;
llint a;
void solve(){
	cin >> n;
	llint all=1;
	llint bad=1;
	for(int i=0;i<n;i++){
		cin >> a;
		all*=3;
		if(a%2==0){
			bad*=2;
		}
	}
	cout << all-bad << endl;

}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
