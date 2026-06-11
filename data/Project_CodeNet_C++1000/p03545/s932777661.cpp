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
    string s ;
    cin >> s ;
    int a = s[0] - '0' , b = s[1] - '0' , c = s[2] - '0' , d = s[3] - '0' ;
    if( a - b - c  - d == 7 ) cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"=7";
    else if ( a - b - c + d  == 7 ) cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"=7";
    else if( a - b + c - d == 7 )  cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"=7";
    else if ( a - b + c + d == 7 ) cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"=7";
    else if ( a + b - c - d == 7 ) cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"=7";
    else if ( a + b - c + d == 7 ) cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"=7";
    else if ( a + b + c -  d == 7 ) cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"=7";
    else if ( a + b + c + d == 7 ) cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"=7";

	return 0 ;
}
