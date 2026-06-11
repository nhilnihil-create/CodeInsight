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
#define rep(i,N) for(int i=0;i<(int)N;++i)
//cout << fixed << setprecision(20) << *** << endl;
typedef long long ll;
using namespace std;
int main()
{
	ll A,B,C,X,Y;
	vector<ll>ANS;
	cin>>A>>B>>C>>X>>Y;
	ANS.push_back(A*X+B*Y);
	if(X>Y){
		ll tmp1,tmp2;
		tmp1=X;
		X=Y;
		Y=tmp1;
		tmp2=A;
		A=B;
		B=tmp2;
	}
	ANS.push_back(X*C*2+(Y-X)*B);
	ANS.push_back(Y*C*2);
	sort(ANS.begin(),ANS.end());
	cout<<ANS.front()<<endl;
}