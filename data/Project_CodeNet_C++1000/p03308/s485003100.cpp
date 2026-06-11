#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	int a,min=10e9+1,max=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if(a>max){
			max=a;
		}
		if(a<min){
			min=a;
		}
	}
   cout<<max-min;


   return 0;
}
