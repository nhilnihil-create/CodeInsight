#include <bits/stdc++.h>
using namespace std;

long long fn(long long mh,long long nm){
	if(nm < 2)
	{
		return 0;
	}
	long long sa = mh - nm;
	long long rt=sa;
	if(nm == 2)
	{
		return rt;
	}
	return rt *nm*(nm-1)/2 + nm*(nm-1)*(nm-2)/6;
}

int main() {
	int n;
	cin >> n;
	int m=0,a=0,r=0,c=0,h=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		char s1 = s.at(0);
		if(s1 == 'M')
		{
			m++;
		}
		else if(s1 == 'A')
		{
			a++;
		}
		else if(s1 == 'R')
		{
			r++;
		}
		else if(s1 == 'C')
		{
			c++;
		}
		else if(s1 == 'H')
		{
			h++;
		}
	}
	long long ans=0;
	long long mh = m + a + r + c + h;
	long long cm = mh*(mh-1)*(mh-2)/6;
	ans = cm - fn(mh,m) - fn(mh,a) - fn(mh,r) - fn(mh,c) - fn(mh,h);
	if(m*a*r==0&&m*a*c==0&&m*a*h==0&&m*r*c==0&&m*r*h==0&&m*c*h==0&&a*r*c==0&&a*r*h==0&&a*c*h==0&&c*h*r==0)
	{
		ans = 0;
	}
    cout << ans << endl;
	return 0;
}
