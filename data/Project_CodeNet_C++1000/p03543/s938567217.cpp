#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]){
        cout << "Yes";
    }else if(s[1] == s[2] && s[2] == s[3]){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}