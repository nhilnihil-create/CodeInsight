#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <list>
#include <math.h>
#include <string.h>
using namespace std;

typedef pair<int, int> P;
#define INF (1LL<<60)
#define int long long
#define ll long long
#define mod 1000000007


signed main(){

	int N, oN;
	cin >> N;
	oN = N;

	if (N == 3){
		cout << "2 3 25" << endl;
		return 0;
	}

	vector<int> v = {};
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(9);

	N -= 4;
	if (N % 2 == 1){
		v.push_back(6);
		N--;
	}

	int n = 1;
	while (N > 0 && 2 * (3 * n + 2) <= 30000){
		v.push_back(2 * (3 * n + 1));
		v.push_back(2 * (3 * n + 2));
		N -= 2;
		n++;
	}
	n = 1;
	while (N > 0 && 3 * (4 * n + 3) <= 30000){
		v.push_back(3 * (4 * n + 1));
		v.push_back(3 * (4 * n + 3));
		N -= 2;
		n++;
	}
	for (int i = 1; v.size()<oN; i++){
		if ((i % 2 == 0 || i%3==0) && find(v.begin(), v.end(), i) == v.end())
			v.push_back(i);
	}



	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
