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
	vector<ll>V;
	cin>>N;
	rep(i,N){
		ll t;
		cin>>t;
		V.push_back(t);
	}
	rep(i,N-1){
		if(V[i]==V[i+1]){
			V[i+1]=20000-i;
			ANS++;
		}
	}
	cout<<ANS<<endl;
}