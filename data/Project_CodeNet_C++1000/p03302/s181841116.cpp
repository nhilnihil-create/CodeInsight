#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;
    if(a+b==15) cout << '+' << endl;
    else if(a*b==15) cout << '*' << endl;
    else cout << 'x' << endl;
    return 0;
}