#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
int main()
{
	vector<vector<ll>>V;
	vector<ll>a(3,0);
	vector<ll>b(3,0);
	rep(i,3){
		vector<ll>v;
		rep(j,3){
			ll t;
			cin>>t;
			v.push_back(t);
		}
		V.push_back(v);
	}
	for(int i=0;i<=2;i++){
		a[0]=i;
		b[0]=V[0][0]-a[0];
		b[1]=V[0][1]-a[0];
		b[2]=V[0][2]-a[0];
		a[1]=V[1][0]-b[0];
		a[2]=V[2][0]-b[0];
		if(V[0][0]==a[0]+b[0]&&V[0][1]==a[0]+b[1]&&V[0][2]==a[0]+b[2]
			&&V[1][0]==a[1]+b[0]&&V[1][1]==a[1]+b[1]&&V[1][2]==a[1]+b[2]
			&&V[2][0]==a[2]+b[0]&&V[2][1]==a[2]+b[1]&&V[2][2]==a[2]+b[2]
		){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}