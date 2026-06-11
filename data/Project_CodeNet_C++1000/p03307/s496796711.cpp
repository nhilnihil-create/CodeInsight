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
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << n;
    }else{
        cout << n * 2;
    }
    
    return 0;
}