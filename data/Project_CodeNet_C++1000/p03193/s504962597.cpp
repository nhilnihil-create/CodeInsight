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
    int n, ans=0;
    ll h, w;
    cin >> n >> h >> w;
    for(int i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        if(h<=a && w<=b) ans++;
    }
    cout << ans << endl;
    return 0;
}