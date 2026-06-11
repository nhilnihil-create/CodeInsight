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
	string s;
	int n,k;	
   cin>>n>>k;
   cin>>s;
   for (int i = 0; i < n; ++i)
   {
   	    (i==k-1)?cout<<(char)tolower(s[i]):cout<<s[i];
   }
   return 0;
}
