#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
bool sortbysec(const pair<pair<string,int>,int> &a, 
              const pair<pair<string,int>,int> &b) 
{ 
	if(a.first.first==b.first.first)
		return a.first.second > b.first.second;
    return (a.first.first < b.first.first); 
} 
int main()
{
	fast;
	ll n;
	cin>>n;
	vector <pair<pair<string,int>,int>> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first.first;
		cin>>v[i].first.second;
		v[i].second=i+1;
	}
	sort(v.begin(),v.end(),sortbysec);
	for(int i=0;i<n;i++)
		cout<<v[i].second<<endl;
	return 0;
}
