#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
#include <map>
using namespace std;
int main(void){
    int n, m; cin >> n >> m;
    int i = 0;
    int max = 0;
    int min = 100000000;
    while (i < m) {
        int a, b;
        cin >> a >> b;
        if (a > max) max = a;
        if (b < min) min = b;
        i++;
    }
    if (min - max < 0) cout << 0 << endl;
    else cout << min - max + 1 << endl;
}