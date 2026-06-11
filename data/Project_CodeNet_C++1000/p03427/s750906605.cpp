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
	string s;
	ll T1=0,T3=0;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		T1=T1+(int)s[i]-48;
	}
	for(ll i=0;i<s.size();i++){
		if(i==0){
			T3=T3+(int)s[i]-49;
		}
		else T3=T3+9;
	}
	cout<<max(T1,T3)<<endl;
}