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
	int i,n,q,c=0;
	cin>>n>>q;
	string s;
	cin>>s;
	vi p(n+3);
	p[0] = 0;
	p[1] = 0;
	for(i=0; i<n ; i++){
		if(s[i-1]=='A' && s[i] == 'C') c++;
		p[i+1] = c;
		}
	//for0(i,n+1) cout<<p[i]<<nw;
	while(q--){
		int l,r,c=0;
		cin>>l>>r;
		cout<<p[r] - p[l]<<nw;
		}
	
	return 0;
}