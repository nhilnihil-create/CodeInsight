#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    int n, cnt = 1;
    cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
        if(l[i]%2 == 0) cnt *= 2;
    }
    cout << pow(3, n) - cnt << endl;
    return 0;
}