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
	ll N,ANS=0;
	bool F=false;
	vector<ll> V;
	vector<vector<ll>>VV;
	cin>>N;
	rep(i,N){
		ll t;
		cin>>t;
		V.push_back(t);
	}

	if(N==1){
		cout<<V[0]<<endl;
		return 0;
	}

	rep(i,101){
		vector<ll>m;
		rep(j,V.size()){
			if(i<V[j])m.push_back(1);
			else m.push_back(0);
		}
		VV.push_back(m);
	}
	rep(i,VV.size()-1){
		rep(j,VV[i].size()-1){
			if(VV[i][j]==1&&j==0)ANS++;
			if(VV[i][j]==0&&VV[i][j+1]==1)ANS++;
		}
	}
	cout<<ANS<<endl;
}