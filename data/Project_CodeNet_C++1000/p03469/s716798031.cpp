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
	rep(i,s.size()){
	    if(i==3)cout<<"8";
	    else cout<<s[i];
	}
	return 0;
}
