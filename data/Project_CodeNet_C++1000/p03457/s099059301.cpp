//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstring>
#include<sstream>
#include <iomanip>

using namespace std;

typedef long long ll ;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vii;
const double pi = 2*acos(0) ;

#define pf		  	printf
#define sf			  scanf
#define pb(a)         push_back(a)
#define mp			make_pair
#define fi			 first
#define se			 second
#define for0(i,n)        for(int i=0;i<n;i++)
#define for1(i,n)        for(int i=1;i<=n;i++)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define lcm(a, b)     ((a)*((b)/gcd(a,b)))
#define sq(a)		   (a)*(a)
#define nw				"\n"
#define abs(x)		fabs(x)
#define pcase(z,x)    cout<<"Case "<<z<<": "<<x<<"\n"
int main()
{
	int n,T,d;
	cin>>n;
	vi t(n+1),x(n+1),y(n+1);
	t[0]=x[0]=y[0] = 0;
	for1(i,n){
		cin>>t[i]>>x[i]>>y[i];
		}
	for0(i,n){
		T = t[i+1] - t[i];
		d = abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]);
		if(d>T || d%2 != T%2){ pf("No"); return 0; }
		}
	pf("Yes");
	
	return 0;
}