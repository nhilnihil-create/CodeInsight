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
	ll base=0,ANS=0;
	cin>>s;
	rep(i,s.size()){
		if(s[i]=='W'){
			ANS=ANS+(i-base);
			base++;
		}
	}
	cout<<ANS<<endl;
}