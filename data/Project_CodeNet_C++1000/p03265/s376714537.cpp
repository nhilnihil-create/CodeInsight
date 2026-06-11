#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2-x1;
    int dy = y2-y1;
    
    cout << x2-dy << " " << y2+dx << " " << x1-dy << " " << y1+dx << endl;
    return 0;
}
