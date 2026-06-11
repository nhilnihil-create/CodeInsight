#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main()
{	int a,b; cin>>a>>b;
	if(a+b==15) cout<<"+";
	else if(a*b==15) cout<<"*";
	else cout<<"x";
	return 0;
}
