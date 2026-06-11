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
	vector<int>V;
	ll t;
	cin>>t;
	V.push_back(t);
	cin>>t;
	V.push_back(t);
	cin>>t;
	V.push_back(t);
	cin>>t;
	V.push_back(t);
	sort(V.begin(),V.end());
	if(V[0]==1&&V[1]==4&&V[2]==7&&V[3]==9){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

}