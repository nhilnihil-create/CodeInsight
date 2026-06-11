#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
const int MOD = 1000000007;
using namespace std;

int main(){
    int a,b;
    float x;
	cin >> a >> b;

    x = float(a + b)/2;

    // cout << x << endl;

    cout << ceil(x) << endl;
}