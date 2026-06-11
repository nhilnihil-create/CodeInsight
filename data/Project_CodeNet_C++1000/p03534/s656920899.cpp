#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

using namespace std;
typedef pair<int, int> pii;

int main(){
    string s;
    cin >> s;
    vector<int> cnts(3);
    rep(i, s.size()){
        int index = s[i] - 'a';
        cnts[index] ++;
    }
    sort(cnts.begin(), cnts.end());
    if(abs(cnts[0] - cnts[2]) < 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
