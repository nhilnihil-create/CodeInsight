#include <bits/stdc++.h>


#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

const int N = 2e5 + 10;


using namespace std;

int main()
{



	IOS;

	int a, b, c, x;

	cin >> a >> b >> c >> x;

	int count = 0;

	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			for (int k = 0; k <= c; k++)
			{
				if (i * 500 + j * 100 + k * 50 == x)
				{
					count++;
				}

			}
		}
	}


	cout << count << endl;



	return 0;
}
