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
    int n;
    cin >> n;
    int val[n],c[n],diff[n];
    
    for(int i=0;i<n;i++) cin >> val[i];
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<n;i++) diff[i]=val[i]-c[i];
    sort(diff,diff+n);
    int sum=0;
    for(int i=n-1;i>=0;i--){
        if(diff[i]>0) sum+=diff[i];
    }
    cout << sum;
}