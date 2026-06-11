/*                                  /   \                                                                   (Hello)//JSM//*/      
/*                                 /*****\                                                                              */
/*     Jai Shree Mataji           /       \ |\| |_| $ |-| K                                                            */
#include<vector>
#include<iostream>
#include<algorithm>                
#include<string.h>                 
#include<bits/stdc++.h>            
#include<cstring>                  
#include<map>                     
#include<cmath>                  
#include<set>
using namespace std;            
#define ll long long int        
#define ld long double
#define MOD 1000000007 
#define PI 3.1415926535897932384626433832795                                               
#define YY cout<<"YES"
#define NN cout<<"NO"
#define EE cout<<"\n"
#define ee cout<<"\n"
#define ne cout<<"-1"
#define pb push_back 
#define fi first
#define se second
#define mkp make_pair    
#define mkt make_tuple
#define sall(v ) sort(v.begin(), v.end())      
#define all(v )  v.begin(), v.end()      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vc vector<char> 
#define vll vector< pair<ll,ll> > 
#define mps map<string ,ll>
#define mpc map<char ,ll>
#define mpl map<ll, ll>
#define pr pair<ll,ll>
#define tpl tuple<ll,ll,ll>
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll t=1;
      
//	   cin>>t;
      

	      while(t--)
{
	/*
5
CHOKUDAI
RNG
MAKOTO
AOKI
RINGO*/
ll n,m;
cin>>n;
string s[n];
map<char,ll> M;
ll ans=0;
fo(i,n)
{
    cin>>s[i];
    M[s[i][0]]++;
}
ans+=M['M']*M['A']*M['R'];
ans+=M['M']*M['A']*M['C'];
ans+=M['M']*M['A']*M['H'];
ans+=M['M']*M['R']*M['C'];
ans+=M['M']*M['R']*M['H'];
ans+=M['M']*M['C']*M['H'];
ans+=M['A']*M['R']*M['C'];
ans+=M['A']*M['R']*M['H'];
ans+=M['A']*M['C']*M['H'];
ans+=M['R']*M['C']*M['H'];



cout<<ans;
ee;
}
return 0;
}













