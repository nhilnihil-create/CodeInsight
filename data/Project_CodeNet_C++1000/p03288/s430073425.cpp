#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using namespace std;
using vi = vector<int64_t>;
using vvi = vector<vi>;

int main(int argc, const char * argv[]) {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t r;
    cin >> r;
    if(r<1200){
        cout << "ABC" << endl;
    }else if(r<2800){
        cout << "ARC" << endl;
    }else{
        cout << "AGC" << endl;
    }
}
