#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    string s;
    cin >> s;
    int k = (int)s.size();
    for(int i = 0; i < k - 8; i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}
