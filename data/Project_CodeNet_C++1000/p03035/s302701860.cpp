#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin>> a >> b;
    if(a >= 13)
    {
        cout << b << endl;
    }
    else if(a >= 6 && a <= 12)
    {
        cout << b/2 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    
    return 0;
}