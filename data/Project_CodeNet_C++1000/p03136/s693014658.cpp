#include<iostream>
#include<vector>
using namespace std;
int find_max(vector<int> v)
{
	int max=0;
	for(vector<int>::size_type i=0;i!=v.size();i++)
	{
		if(v[i]>max)
		max=v[i];
	}
	return max;
}
int main()
{
	int n,i=0;
	cin>>n;
	vector<int> body;
	int m;
	while(i<n&&cin>>m)
	{
	body.push_back(m);
	i++;
}
int sum=0;
for(vector<int>::size_type i=0;i!=body.size();i++)
sum+=body[i];
if((sum-find_max(body))>find_max(body))
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
return 0;
}