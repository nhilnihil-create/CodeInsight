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
	ll N;
	double ave=0;
	vector<pair<double,ll>>V;
	cin>>N;
	rep(i,N){
		pair<double,ll>pa;
		cin>>pa.first;
		pa.second=i;
		V.push_back(pa);
		ave=ave+pa.first;
	}
	ave=ave/N;
	rep(i,N){
		V[i].first=abs(ave-V[i].first);
	}
	sort(V.begin(),V.end());
	cout<<V[0].second<<endl;
}
