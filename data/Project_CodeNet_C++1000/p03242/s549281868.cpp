//AUTHOR:BlackBox Inc.//
#include<bits/stdc++.h>
#include<unordered_map>
#include<tr1/unordered_map>
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vlli vector<long long int>
#define vvi vector<vector<int>>
#define endl "\n"
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define lin1(x) ll int x; x = scan();
#define lin2(x,y) ll int x, y; x = scan(), y = scan();
#define lin3(x,y,z) ll int x, y, z; x = scan(), y = scan(), z = scan();
#define pb(x) push_back(x)
#define makep(x,y) make_pair(x,y)
#define mx(a,b) (a)>(b)?(a):(b)
#define mn(a,b) (a)<(b)?(a):(b)
#define fori(s,e) for(i=s;i<=e;i++)
#define forj(s,e) for(j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define brep(i,s,e) for(int i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define bits1(x) __builtin_popcount(x)
#define pi 3.14159265358979323846264338327950
#define MOD7 1000000007
#define MOD9 1000000009
#define cn cin>>
#define co cout<<
#define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace std::tr1;

int main()
{


long long x;
cin>>x;
// vector<int>rohan;
long long rohan=0;
while(x!=0){
	int count=x%10;
	if (count==9)
	{
		rohan=rohan*10+1;
		/* code */
	}
	else{

		rohan=rohan*10+9;
	}
	x=x/10;
}
int rahul=0;
while(rohan!=0){
	int count=rohan%10;
	rahul=rahul*10+count;
	rohan/=10;
}
cout<<rahul<<endl;

return 0;
}


