#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,K;
  	cin>>n>>K;
  	string s;
  	cin>>s;
  	if(n==1)
    {
      cout<<1<<endl;
      return 0;
    }
  	vector<int>o;
  	for(int i=0;i<n;i++)
    {
      if(s[i]=='1' && i==0)o.push_back(i);
      else if(s[i-1]=='0' && s[i]=='1')o.push_back(i);
    }
  	vector<int>l;
  	for(int i=n-1;i>=0;i--)
    {
      if(s[i]=='1' && i==n-1)l.push_back(i);
      else if(s[i]=='1' && s[i+1]=='0')l.push_back(i);
    }
  	int os=o.size();
  	int ls=l.size();
  	if(os==1 && s[0]=='1' && s[n-1]=='1')
    {
      cout<<n<<endl;
      return 0;
    }
  	if(os==0 && ls==0)
    {
      cout<<n<<endl;
      return 0;
    }
  	sort(l.begin(),l.end());
  	int ans=0;
  	
  	for(int i=0;i<os;i++)
    {
		ans=max(ans,abs(l[min((i+K),ls-1)]-o[i]+1));
      	
    }
  	if(s[0]=='0')ans=max(ans,l[min(0+K-1,ls-1)]+1);
  	if(s[n-1]=='0')ans=max(ans,n-o[os-K]);
    cout<<ans<<endl;
    return 0;
}	