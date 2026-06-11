
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 int main(){

  int c[3][3];
   int x=0,y=0;

   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
            cin>>c[i][j];
   }

if(c[0][0]-c[0][1]==c[1][0]-c[1][1])
	{
		if(c[1][0]-c[1][1]==c[2][0]-c[2][1])
		{
			x=1;
		}
	}
	if(c[0][1]-c[0][2]==c[1][1]-c[1][2])
	{
		if(c[1][1]-c[1][2]==c[2][1]-c[2][2])
		{
			y=1;
		}
	}

	if(x == 1 && y == 1)
            cout<<"Yes"<<endl;
      else
            cout<<"No"<<endl;

 return 0;
 }
