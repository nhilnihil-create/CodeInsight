#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
int A, B, T;
cin >> A >> B >> T;
int ans = 0;
for(int i = A; i <= T; i = i+A)ans += B;
cout <<ans << endl;


}
