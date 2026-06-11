#include <bits/stdc++.h>

#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	string s;
  	cin >> s;
  	int aa, bb;
  	aa = (int)(s[0] - '0') * 10 + (int)(s[1] - '0');
  	bb = (int)(s[2] - '0') * 10 + (int)(s[3] - '0');
  	bool YYMMflag = false, MMYYflag = false;
  	if(bb>0 && bb <= 12) YYMMflag = true;
  	if(aa>0 && aa <= 12) MMYYflag = true;
  	if(YYMMflag && MMYYflag) {
    	cout << "AMBIGUOUS" << endl; 
    } else if(YYMMflag) {
     	cout << "YYMM" << endl; 
    } else if(MMYYflag) {
        cout << "MMYY" << endl;
    } else {
        cout << "NA" << endl; 
    }
}