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
	ll A,B;
	cin>>A>>B;
	if(A%2==0){
		if((A/2)>=B)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else{
		if((A/2)+1>=B)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}