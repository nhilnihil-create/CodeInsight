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
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	double N;
	ll ANS=1;
	cin >> N;
	for(ll i=1;i<=sqrt(N);i++){
		ANS=i*i;
	}
	cout << ANS << endl;
}