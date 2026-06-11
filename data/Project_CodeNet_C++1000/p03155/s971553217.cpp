#include <iostream>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void){
    int n, h, w;
    cin >> n;
    cin >> h;
    cin >> w;
    cout << (n - h + 1) * (n - w + 1) << endl;
    
}
