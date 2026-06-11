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
	cin>>s ;
	n = s.size() ;
	if(s[0] == '0' || s[n-1] == '1')
		return cout<<"-1\n" , 0 ;
	for(int i = 0 ; i < n-1 ; ++i)
	{
		if(s[i] != s[n-2-i])
			return cout<<"-1\n" , 0 ;
	}
	int now = 1 , cur = 1 ;
	for(int i = n-2 ; i >= 0 ; --i)
	{
		cur++ ;
		cout<<now<<" "<<cur<<"\n" ;
		if(s[i] == '1')
			now = cur ;
	}
	return 0 ;
}		