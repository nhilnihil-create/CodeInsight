#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2 ;
    int l1,l2;
    l1 = (x2 -x1);
    l2 = (y2 -y1);
    int x3,y3,x4,y4;
    x3 = x2 + (y1 -y2);
    y3 = y2 + (x2 -x1);
    x4 = x1 + (y1 -y2);
    y4 = y1 + (x2 -x1);
    double center_x_1,center_x_2,center_y_1,center_y_2;
    center_x_1 = (double)((x1+x3)/2);
    center_y_1 = (double)((y1+y3)/2);
    center_x_2 = (double)((x2+x4)/2);
    center_y_2 = (double)((y2+y4)/2);
    if((center_x_1!=center_x_2)||(center_y_1!=center_y_2)){
        cout << "error" << endl;
    }
    else{
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }
}