#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <math.h>
#include <functional>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
int main(){
    int s;
    cin >> s;
    int y = s / 100;
    int m = s % 100;
    if(1 <= y && y <= 12){
        if(1 <= m && m <= 12) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    } else{
        if(1 <= m && m <= 12) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
    return 0;
}