#include <iostream>
#include <vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
#include<string>
using namespace std;
int main() {
    long long int a, b,n;
    cin >> a >>  b;
    if (a % b == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << a << endl;
 }