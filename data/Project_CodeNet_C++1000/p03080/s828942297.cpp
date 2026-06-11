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
    
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    REP(i, n){
        cnt += (s[i] == 'R' ? 1: -1);
    }
    if(cnt > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
