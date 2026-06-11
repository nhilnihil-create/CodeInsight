#include <bits/stdc++.h>
using namespace std;
int main(){
long double n, m, d, ans=0;
cin >> n >> m >> d;
ans=(d)?2*(n-d)*(m-1)/(n*n):(n-d)*(m-1)/(n*n);
cout << setprecision(15) << ans << "\n";
}