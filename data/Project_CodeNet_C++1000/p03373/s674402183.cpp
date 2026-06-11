#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int mi = min(x, y);
    int cost;

    if(a+b > 2*c){
        cost += 2*c*mi;
    }
    else cost += mi*(a+b);

    int ma = max(x, y);
    int z = ma - mi;

    if(x-y >= 0){
        if(a > 2*c) cost += z*2*c;
        else cost += z*a;
    }

    else{
        if(b > 2*c) cost += z*2*c;
        else cost += z*b;
    }

    cout << cost << endl;

}