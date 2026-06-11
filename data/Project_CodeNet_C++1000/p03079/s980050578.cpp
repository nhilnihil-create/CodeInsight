#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>
#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;
using ll = long long;
ll MOD = 1e9+7;


int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
