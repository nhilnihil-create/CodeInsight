#include <iostream>
using namespace std;
int main(void){
double a,b;
cin >> a >> b;
double A = (a + b) / 2.0;
int  B = (a + b)/2;
double T = (a + b) / 2.0 - B;
if(T == 0.0)
cout << A <<endl;
else
cout << A - T + 1 << endl;

}