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
#define n	5
bool cmp(int a, int b){
	if(a%10==0) return a>b;
	if(b%10==0) return a<b;
	return a%10 > b%10;
	}
int main()
{
	int x[6];
	for0(i,n) cin>>x[i];
	sort(x,x+n,cmp);
	int t,s=0;
//	for0(i,n) cout<<x[i]<<nw;
	for0(i,n-1){
		t = (ceil((x[i]/10.0))) * 10;
		s += t;
		}
	s += x[n-1];
	cout<<s<<nw;
	return 0;
}