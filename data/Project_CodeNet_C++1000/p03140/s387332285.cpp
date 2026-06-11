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
	ll N,a=0;
	string A,B,C;
	vector<ll>ANS;
	cin>>N>>A>>B>>C;
	rep(i,N){
		if(A[i]==B[i]&&A[i]!=C[i])a++;
		if(A[i]==C[i]&&A[i]!=B[i])a++;
		if(B[i]==C[i]&&B[i]!=A[i])a++;
		if(A[i]!=B[i]&&B[i]!=C[i]&&A[i]!=C[i])a+=2;
	}
	cout<<a<<endl;
}