#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
string N;
cin >> N;

int Z = 0, O = 0;
for(auto c : N){
if(c == '0')Z++;
else O++;
}
cout << min(Z, O)*2 << endl;
}

