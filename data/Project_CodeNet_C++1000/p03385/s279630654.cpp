#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	string s;
	cin>>s;
	int a=0,b=0,c=0;
	rep(i,3){
	    if(s[i]=='a')a++;
	    else if(s[i]=='b')b++;
	    else c++;
	}
	if(a*b*c)cout<<"Yes";
	else cout<<"No";
	return 0;
}