#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<numeric>
#include<list>
#include<stack>
#include<sstream>
#define lli unsigned long long int
#define h 100
#define pf push_front
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
using namespace std;
int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL) ;
  lli t, n, i, flag=0, sum, x, a, b, j;
  cin>>a>>b;
  sum=0;
  for(x=a;x<=b;x++) 
  {
  	stringstream ss;
  	string y;
  	ss<<x;
  	ss>>y;
  	i=0;
  	flag=0;
  	j=y.size()-1;
  	for(;i<(y.size()/2);j--,i++) 
  	if(y[i]!=y[j]) {flag=1;break;} 
  	if(flag) continue;
  	else sum+=1;
  } 
  cout<<sum<<endl;
  return 0;
} 
