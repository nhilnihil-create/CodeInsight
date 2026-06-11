#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
	ll K,A,B;
	cin>>K>>A>>B;

	if(K>=(A+1)&&B-A>1)
	{  
		ll fc=K-(A-1);
		ll cnt=fc/2;
		ll c=B+(cnt-1)*(B-A);
		ll cc=fc%2;
		cout<<c+cc<<endl;
	}
	else
	{
		cout<<K+1<<endl;
	}
}