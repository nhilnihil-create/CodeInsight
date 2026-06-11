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
	int N,A,B;
	cin >> N >> A >> B;
	if(A*N<=B){
		cout << A*N << endl;
	}
	else{
		cout << B << endl;
	}

}