#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
string s;
cin >> s;
int s1 = stoi(s.substr(0,2));
int s2 = stoi(s.substr(2,2));
bool isM1 = false,isM2 = false;
 
 if(s1 >= 1 && s1 <= 12) isM1 = true;
if(s2 >= 1 && s2 <= 12) isM2 = true;
if(isM1 && isM2)cout << "AMBIGUOUS" << endl;
else if(isM1) cout << "MMYY" << endl;
else if(isM2) cout << "YYMM" << endl;
else cout << "NA" << endl;

}
  
