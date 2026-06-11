#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int N, x,count=0,sum=0;
	cin >> N >> x;
	vector<int> a(N);
	rep(i, N) { 
		cin >> a[i];
		
	}
	
	sort(a.begin(), a.end());

	for (int i = 0; i<N; i++)
	{
		x -= a[i];
		if (x < 0)break;
		count++;
	}
	if (x > 0)--count;
	
	cout << count << endl;
}