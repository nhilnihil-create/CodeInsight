#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
 


int main()
{
	//ifstream cin("input.txt");
	string s;
	cin>>s;
	ll n = s.length();

	int i = 0, cnt = 0;
	int stk = 0, zstk = 0;
	while(i < n - 1)
	{
		if((s[i] == '1' && s[i+1] == '0' )||(s[i] == '0' && s[i+1] == '1'))
		{
			cnt +=1;
			i += 2;
		}
		else if(s[i] == '1' && s[i+1] == '1')
		{
			if(zstk > 0)
			{
				zstk--;
				cnt++;
			}
			else
				stk+=1;
			i++;
		}
		else if(s[i] == '0' && s[i+1] == '0')
		{
			if(stk > 0){
				stk--;
				cnt ++;
			}
			else
				zstk ++;
			i++;
		}
	}
	if(s[i] == '1' && zstk > 0 ||(s[i] == '0' && stk > 0))
		cnt++;

	cout<<cnt * 2;
	
}
