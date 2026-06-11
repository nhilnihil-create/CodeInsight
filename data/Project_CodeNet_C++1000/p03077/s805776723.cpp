#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

#define INF  -10000000000

int main()
{
    long long n;
    long long q[5];
    long long m = 10000000000000000;
    
    cin >> n;
    for (int i = 0;i < 5;i++){
        cin >> q[i];
        m = min(m,q[i]);
    }
    if (n >= m && n%m == 0){
        cout << 4+n/m << endl;
    }
    else {
        cout << 5+n/m << endl;
    }
    
    
}
