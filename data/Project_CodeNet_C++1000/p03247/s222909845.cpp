
 #include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <set>
 #include <map>
 #include <vector>
 #include <list>
 #include <algorithm>
 #include <cstring>
 #include <cmath>
 #include <string>
 #include <queue>
 #include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
 #include <cassert>
 #include <iomanip>        //do setprecision
 #include <ctime>
 #include <complex>
 using namespace std;

 #define FOR(i,b,e) for(int i=(b);i<(e);++i)
 #define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
 #define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
 #define REP(x, n) for(int x = 0; x < (n); ++x)

 #define ST first
 #define ND second
 #define PB push_back
 #define PF push_front
 #define MP make_pair
 #define LL long long
 #define ULL unsigned LL
 #define LD long double
 #define pii pair<int,int>
 #define pll pair<LL,LL>

 const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
 const int mod=1000000007;

 int main(){
	 int n,x[1111]={},y[1111]={};
	 int xx[1111]={},yy[1111]={};
	 cin>>n;
	 int f[2]={};
	 FOR(i,0,n){
		 cin>>x[i]>>y[i];
		 if(x[i]>0)xx[i]=x[i];
		 else xx[i]=-x[i];
		 if(y[i]>0)yy[i]=y[i];
		 else yy[i]=-y[i];
		 f[(xx[i]+yy[i])&1]=1;
	 }
	 if(f[0]==f[1]){
		 cout<<-1<<endl;
		 return 0;
	 }
	 LL arm[42]={};
	 int m=36;
	 FOR(i,0,m){
		 arm[i]=1LL<<i;
	 }
	 if(f[0]){
		 arm[m]=1;
		 m++;
	 }
	 cout<<m<<endl;
	 FOR(i,0,m){
		 if(i!=m-1)cout<<arm[i]<<" ";
		 else cout<<arm[i]<<endl;
	 }
	 int dx[4]={0,1,0,-1};
	 int dy[4]={1,0,-1,0};
	 char dr[4]={'U','R','D','L'};
	 FOR(i,0,n){
		 LL xx=0,yy=0;
		 char s[42]={};
		 FORD(j,m,0){
			 LL nd=0,dist=1LL*mod*mod;
				FOR(d,0,4){
					LL nx=xx+dx[d]*arm[j];
					LL ny=yy+dy[d]*arm[j];
					LL ndist=fabs(nx-x[i])+fabs(ny-y[i]);
					if(dist>ndist){
						dist=ndist;
						nd=d;
					}
				}
				s[j]=dr[nd];
				xx=xx+dx[nd]*arm[j];
				yy=yy+dy[nd]*arm[j];
				//cout<<i<<" j:"<<j<<" arm[j]:"<<arm[j]<<" xx:"<<xx<<" yy:"<<yy<<endl;
		 }
		 FOR(j,0,m){
			 cout<<s[j];
		 }
		 cout<<endl;
	 }


   return 0;
 }
