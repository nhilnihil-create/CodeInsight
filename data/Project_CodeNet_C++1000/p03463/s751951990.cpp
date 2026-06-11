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

ll sum_keta(ll a){
	ll A=a,SUM=0;
	while(A!=0){
		SUM=SUM+A%10;
		A=A/10;
	}
	return SUM;
}

int main()
{
	ll N,A,B;
	string s;
	cin>>N>>A>>B;
	for(;;){
		if(A+1==B){
			s="Borys";
			break;
		}
		A++;
		if(B-1==A){
			s="Alice";
			break;
		}
		B--;
	}
	cout<<s<<endl;
}