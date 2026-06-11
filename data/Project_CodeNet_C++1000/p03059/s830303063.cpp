#include<iostream>
using namespace std;
int main()
{
    int s,k,x,A,B,t;
    double T;
    cin >> A >> B >> t;
    T = t+0.5;
    k = T/A;
    s = B*k;
    cout << s <<endl;
    return 0;
}
