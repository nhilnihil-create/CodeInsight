#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

const int INF = INT_MAX;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n, INF);
    deque<int> dq;
    v[1] = 1;
    dq.push_back(1);
    while(!dq.empty()){
        int a = dq.front();
        dq.pop_front();

        int b = (a + 1) % n;
        if(v[a] + 1 < v[b]){
            v[b] = v[a] + 1;
            dq.push_back(b);
        }
        int c = (a * 10) % n;
        if(v[a] < v[c]){
            v[c] = v[a];
            dq.push_front(c);
        }
    }
    cout << v[0] << endl;

    return 0;
}
