#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] ;
int n ;
string s ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	int ans = 0 ;
	int cnt1 = 0 , cnt2 = 0 , cnt3 = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>s ;
		for(int j = 0 ; j < s.size() - 1 ; ++j)
		{
			if(s[j] == 'A' && s[j+1] == 'B')
				ans++ ;
		}
		if(s.back() == 'A' && s[0] == 'B')
			cnt3++ ;
		else if(s[0] == 'B')
			cnt2++ ;
		else if(s.back() == 'A')
			cnt1++ ;
	}
	if(cnt3 > 0 && cnt1 == 0 && cnt2 == 0)
		cnt3-- ;
	ans += min(cnt1 , cnt2) ;
	int x = max(cnt1 , cnt2) - min(cnt1 , cnt2) ;
	ans += min(x , cnt3) ;
	cnt3 -= min(x , cnt3) ;
	return cout<<ans + cnt3<<"\n" , 0 ;
}		