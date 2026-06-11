#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdint>
#include <istream>
#include <sstream>
#include <cctype>
#include <functional>
#include <iomanip>
#define rep(i,N) for(ll i=0;i<N;i++)
#define disp(a) cout << a << endl;
#define PI 3.1415926535897932384626433
//cout << fixed << setprecision(20) << ** << endl;
typedef long long ll;
using namespace std;

double deg2rad(double degree)
{
    return degree * PI / 180.0000000000;
}
int main()
{
	vector<int>V,C;
	rep(i,6){
		ll t;
		cin>>t;
		V.push_back(t);
	}
	C.push_back(count(V.begin(),V.end(),1));
	C.push_back(count(V.begin(),V.end(),2));
	C.push_back(count(V.begin(),V.end(),3));
	C.push_back(count(V.begin(),V.end(),4));
	sort(C.begin(),C.end());
	if(C.back()==3){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
}