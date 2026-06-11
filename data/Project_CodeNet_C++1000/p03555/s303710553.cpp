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
	string s1,s2;
	cin >> s1 >> s2;
	if(s1[1]==s2[1]&&s1[0]==s2[2]&&s1[2]==s2[0]){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

}