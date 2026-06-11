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
	ll N,A,B;
	vector<ll>MIN(3,0);
	cin>>N>>A>>B;
	rep(i,N){
		ll t;
		cin>>t;
		if(t<=A)MIN[0]++;
		if(t>A&&t<=B)MIN[1]++;
		if(t>B)MIN[2]++;
	}
	sort(MIN.begin(),MIN.end());
	cout<<MIN[0]<<endl;
}