#include <iostream>
#include <bits/stdtr1c++.h>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
bool oppositeSigns(int x, int y) { return ((x ^ y) < 0); }
using namespace std;
typedef long long ll;
const int N = 100001;
const int MOD = 1000000007;
vector<int> adj[100001];
bool visited[100001];
vector<string> res;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b, t;
    cin >> a >> b >>t;
    cout << (t/a)*b;
    return 0;
}