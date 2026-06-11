#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

using ll = long long;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int res = n;

    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]) res = min(res, max(i,n-i));
    }

    cout << res << endl;

    return 0;
}
