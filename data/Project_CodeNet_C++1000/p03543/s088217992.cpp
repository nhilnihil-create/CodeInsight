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
    string jamil ;
    cin >> jamil ;
    bool ans = 0 ;
    for ( int i = 0 ; i < jamil.size() - 2 ; i++ )
    {
        if ( jamil[i] == jamil[i+1] && jamil[i+2] == jamil[i+1] )
            ans = 1 ;
    }
    cout << ( ans ? "Yes" : "No" ) ;
	return 0 ;
}
