#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n,a,b,p,q1=0,q2=0,q3=0;
    cin >> n;
    cin >> a >> b;
    for (int i=0;i<n;i++) {
        cin >> p;
        if (p <= a) {q1++;}
        else if (p > a && p <=b) {q2++;}
        else {q3++;}
    }
    cout << min({q1,q2,q3}) << endl;
    return 0;
}