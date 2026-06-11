#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
#include <deque>
using ll = long long;
using Graph = vector<vector<int>>;
#include <queue>
#include <stack>
#include <stdlib.h>


int main(){

    int x1,y1,x2,y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int a = x2 - x1;
    int b = y2 - y1;

    int x3 = x2 - b;
    int y3 = y2 + a;
    int x4 = x3 - a;
    int y4 = y3 - b;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;


    return 0; 
}