#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(abs(a-c) <= d || ((abs(a-b) <= d) && abs(b-c) <= d)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}   