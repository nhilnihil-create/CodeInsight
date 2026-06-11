#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    int sum = a+b, sub = a-b, mul = a*b;
    int m = max(sum, sub);
    cout << max(m, mul); 
    cout << endl;
}
