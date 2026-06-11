//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sublime(){ 
	#ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
      }
	
int main()
{   
   //sublime();
	  ll n,i;
	   ll a,b;
	   cin>>a>>b;
	   if(a>=13)
	   cout<<b;
	   else
	   if(a>=6 && a<=12)
	   cout<<b/2;
	   else
	   cout<<0; 
	   
	return 0;
}