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
	ll N,P0=0,ANS;
	vector<ll>V;
	cin>>N;
	rep(i,N){
		ll t;
		cin>>t;
		if(t%2==0)P0++;
	}
	N=int(pow(3,double(N)));
	ANS=N-int(pow(2,double(P0)));
	cout<<ANS<<endl;
}