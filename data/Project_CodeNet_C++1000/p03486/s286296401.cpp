#include<bits/stdc++.h>
using namespace std;
int comp(const char &a,const char &b)
{
  return a>b;
}
int main()
{
	string s;
  	string t;
  	cin>>s>>t;
  	sort(s.begin(),s.end());
  	sort(t.begin(),t.end(),comp);
    if(s<t)cout<<"Yes"<<endl;
  	else cout<<"No"<<endl;
	return 0;
}