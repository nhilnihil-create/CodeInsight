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
    
    vector<int> n(4);
    REP(i, 4){
        cin >> n[i];
    }
    sort(n.begin(), n.end());
    if(n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
