#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
string S;
cin >> S;
ll N;
cin >> N;
ll lo = S.size();

for(int i = 0; i < min(lo, N); i++){
if(S[i] >= '2') {cout << S[i] << endl; return 0;}

}
cout << '1' << endl;
return 0;

}