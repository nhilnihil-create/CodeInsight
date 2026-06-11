#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	cout<<a[2]-a[0]<<endl;
	return 0;
}