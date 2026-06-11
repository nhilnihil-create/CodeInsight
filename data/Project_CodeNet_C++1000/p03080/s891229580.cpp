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
	ll N,R=0,B=0;
	string S;
	cin>>N>>S;
	rep(i,N){
		if(S[i]=='R')R++;
		else B++;
	}
	if(R>B)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}