#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1010;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code
char ans[100][100];

int main()
{
	int a, b;
	cin>>a>>b;
	a--;b--;
	for(int i=0; i<50; i+= 2)
	{
		for(int j=0; j <50; j+=2)
		{
			if(a <= 0)
				{i = 50; j = 50;break;}
			ans[i][j] = '.';
			a--;
		}
	}
	for(int i=99; i>=50; i-= 2)
	{
		for(int j=0; j <50; j+=2)
		{
			if(b <= 0)
				{i = 50; j = 50;break;}
			ans[i][j] = '#';
			b--;
			
		}
	}
	cout<<100<<" "<<100<<endl;
	rep(i, 0, 50){
		rep(j, 0, 100){
			if(ans[i][j] == '.')
				cout<<ans[i][j];
			else
				cout<<'#';
		}
		cout<<endl;
	}
	rep(i, 50, 100){
		rep(j, 0, 100){
			if(ans[i][j] == '#')
				cout<<ans[i][j];
			else
				cout<<'.';
		}
		cout<<endl;
	}
}
