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
	ll A,B,K;
	cin>>A>>B>>K;
	rep(i,K){
		if(i%2==0){
			if(A%2==1)A--;
			B=B+A/2;
			A=A-A/2;
		}
		else{
			if(B%2==1)B--;
			A=A+B/2;
			B=B-B/2;
		}
	}
	cout<<A<<" "<<B<<endl;
}