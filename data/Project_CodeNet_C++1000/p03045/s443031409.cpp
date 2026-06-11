#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int P[100010];
int used[100010];

void init(int N){ 
	for (int i = 0; i < N; ++i) P[i] = i;
}

int root(int a){ 
	if (P[a] == a) return a; 
	return (P[a] = root(P[a])); 
}

bool is_same_set(int a, int b){ 
	return root(a) == root(b);
}

void unite(int a, int b){ 
	P[root(a)] = root(b);
}

int main(){
	int n, m;
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		unite(x-1, y-1);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (!used[root(P[i])]){
			used[root(P[i])] = true;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}