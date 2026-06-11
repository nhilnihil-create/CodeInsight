#include<bits/stdc++.h>
#define ll      long long
#define pb	    push_back
#define F	    first
#define S	    second
#define B	    begin()
#define E	    end()
#define pii     pair < ll , ll >
#define FASTIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std ;
int jamil ;
int main()
{
    FASTIO
    int jamil ;
    cin >> jamil ;
    ll l[87] ;
    l[0] = 2 ;
    l[1] = 1 ;
    for ( int i = 2 ; i <= jamil ; i++ )
    {
        l[i] = l[i-1] + l[i-2] ;
    }
    cout << l[jamil] ;
	return 0 ;
}
