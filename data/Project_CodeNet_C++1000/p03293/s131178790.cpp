#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
string S, T;
cin >> S >> T;
string Si = S;
string ans = "No";
if(S == T)ans = "Yes";
for(int i = 0; i < 115; i++){
char a = Si[0];
Si.erase(Si.begin());
Si += a;
if(Si == T)ans = "Yes";
}
cout << ans << endl;


}
