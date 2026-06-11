#include<iostream>
using namespace std;
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<algorithm>
#define int long long int
#define mod 1000000007
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	set<int> st;
	int j;
	for(j=1;j*j<=n;j++)
	{
		if(n%j==0)
		{
			int p=j;
			int q=n/j;
			int m=q-1;
			if(m!=0&&n%m==p)
			{
				st.insert(m);
			}
			p=n/j;
			q=j;
			m=p-1;
			if(m!=0&&n%m==q)
			{
				st.insert(m);
			}
		}
	}
	int answer=0;
	for(int x:st)
	  answer+=x;
    cout<<answer<<endl;
}
