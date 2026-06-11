#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <regex>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

int main() {
    string s;
    cin >> s;
    regex re("A?KIHA?BA?RA?");
    bool res=regex_match(s,re);
    cout << (res?"YES":"NO") << endl;
    return 0;
}