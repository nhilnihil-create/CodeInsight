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

ll Factorial(ll a){
	ll b=1;
	for(ll i=a;i>=1;i--){
		b=b*i;
	}
	return b;
}

int main()
{
	ll N;
	string S;
	string base="keyence";
	cin>>S;
	N=S.size()-7;
	rep(i,S.size()-N){
		string t=S;
		t.erase(i,N);
		if(t==base){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}