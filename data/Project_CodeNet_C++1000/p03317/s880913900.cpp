#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <math.h>
#include <numeric>
#include <stdio.h>
#include <cstdio>

using namespace std;

int main(){
    int n,k, a;
    cin >> n;
    cin >> k;
for (int i = 0; i < n; i++){
        cin >> a;
    }
    if ((n - 1) % (k - 1))
        cout << (n - 1) / (k - 1) + 1<< endl;
    else
        cout << (n - 1) / (k - 1) << endl;
    
    
    
}
