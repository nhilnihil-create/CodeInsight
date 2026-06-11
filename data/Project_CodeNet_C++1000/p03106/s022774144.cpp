// ABC_120_B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++n)

int main()
{
	int a, b, k;
	cin >> a >> b >> k;

	vector<int> v;

	int mini = min(a, b);
	for(int i = 1; i <= mini; ++i){
		if(a % i == 0 && b % i == 0) {
			v.push_back(i);
	  }
		else continue;
	}

	sort(v.rbegin(), v.rend());
	//for(auto item : v) cout << item << " ";
  cout << v[k-1] << "\n";

  return 0;
}      