#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,c;
	cin>>n>>c;
	int ans = 0;
	multiset<ar<int,2>> m;
  	vector<ar<ll,3> > v;
  for(int i = 0; i<n; i++)
  {
	int j,k,l;
    cin>>j>>k>>l;
    v.pb({j,k,l});
  }
  sort(v.begin(),v.end());
	for(int i = 0; i<n; i++)
	{
		int j,k,l;
		j = v[i][0];
      	k = v[i][1];
      	l = v[i][2];
		auto y = m.lower_bound({0,0});
		int flag = 1;
		for(;y!=m.end();y++)
		{
			ar<int,2> t = *y;
          if(t[0]<j)
			{
				m.erase(y);
				m.insert({k,l});
				flag = 0;
				break;
			}
			else if(t[0]==j && t[1]==l)
			{
				m.erase(y);
				m.insert({k,l});
				flag = 0; 
				break;
			}
			else if(t[0]>j)
				break;
		}
		if(flag)
			m.insert({k,l});
	}
	cout<<m.size()<<endl;
	return 0;
}