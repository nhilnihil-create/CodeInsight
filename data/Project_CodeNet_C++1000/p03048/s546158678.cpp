#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define lli long long int
#define rep(i,n) for(int i=0; i<n; i++)
#define loop(i, j, n) for(int i=j; i<n; i++)
using namespace std;
using Graph = vector<vector<int>>;
int main()
{
	int r, g, n, cnt=0;
	double b, z;
	cin >> r >> g >> b >> n;

	rep(x,3001){
		rep(y,3001){
			z = (n-r*x-g*y)/b;
			if(z == (int)z && (z >= 0 && z <= 3000)){
				cnt++;
			}
		}
	}
	cout << cnt <<endl;
	return 0;
}