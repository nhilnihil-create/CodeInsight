#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int main(){
	int n;cin>>n;
	string s[110];
	map<string,int> kosuu;
	string ans="Yes";
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
	{
		kosuu[s[i]]++;
		if(i>=1)
		{
			char l=s[i-1][s[i-1].length()-1],f=s[i][0];
			if(kosuu[s[i]]>=2 || (l!=f))
			{
				ans="No";
				break;
			}
			
		}
	} 
	cout<<ans<<"\n";
	return 0;
}