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
    
    string s;
    cin >> s;
    int cnt = 0;
    REP(i, s.size()){
        cnt += s[i]=='o';
    }
    cnt += 15-s.size();
    if(cnt >= 8){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
