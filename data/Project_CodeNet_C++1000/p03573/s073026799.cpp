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
	int A,B,C;
	cin >> A >> B >> C;
	if(A!=B&&B==C){
		cout << A << endl;
	}
	else if(A!=B&&A==C){
		cout << B << endl;
	}
	else{
		cout << C << endl;
	}
}