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
    int a[n];
    for(int i = 0; i < n; i++){
    cin >> a[i];    
    }
    sort(a, a+n);
    reverse(a, a+n);
    int g = 0;
    for(int j = 0; j < n; j++){
        g = g + a[j];
    }
    g = g - a[0];
    if(a[0] < g){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}