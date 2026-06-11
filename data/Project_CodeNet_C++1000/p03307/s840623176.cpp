#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){

unsigned long long N;
cin >> N;

unsigned long long ans = N;

if(N % 2 == 0){
     cout << ans << endl;
}
else{
     cout << ans * 2 << endl;
}

return 0;
}