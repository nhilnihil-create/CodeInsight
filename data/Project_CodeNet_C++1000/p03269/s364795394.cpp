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
#include <array>
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
#include <memory>
#include <regex>
using namespace std;

class Edge
{
public:
    int a, b, cost;
    Edge(int a, int b, int cost){
        this->a = a;
        this->b = b;
        this->cost = cost;
    }
};

int main()
{
    int l;
    cin >> l;

    int n = 1;
    vector<Edge> edges;
    for(int i=0; (2<<i)<=l; ++i){
        edges.push_back(Edge(i, i+1, 0));
        edges.push_back(Edge(i, i+1, 1<<i));
        ++ n;
    }
    int cnt = 1 << (n - 1);

    for(int i=n-1; i>=0; --i){
        int x = 1 << i;
        if(x <= l - cnt){
            edges.push_back(Edge(i, n-1, cnt));
            cnt += x;
        }
    }

    int m = edges.size();
    cout << n << ' ' << m << endl;
    for(int i=0; i<m; ++i){
        int a = edges[i].a + 1;
        int b = edges[i].b + 1;
        cout << a << ' ' << b << ' ' << edges[i].cost << endl;
    }

    return 0;
}
