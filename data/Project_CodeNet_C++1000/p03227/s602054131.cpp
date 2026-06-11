#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define ALL(v) v.begin(),v.end()

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    if (s.size() == 2)
    {
        cout << s << endl;
    }
    else
    {
        reverse(ALL(s));
        cout << s << endl;
    }
}