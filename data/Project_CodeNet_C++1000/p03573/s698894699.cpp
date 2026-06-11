#include <bits/stdc++.h>
using namespace std;
int main() {
int A,B,C;
cin >> A >> B >> C;
if(A!=B && A!=C){
    cout << A; return 0;
}
if(B!=A && B!=C){
    cout << B; return 0;
}
cout << C;
return 0;
}