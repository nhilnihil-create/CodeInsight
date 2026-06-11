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
    int n, k;
    cin >> n >> k;
    if(2*k-1<=n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}