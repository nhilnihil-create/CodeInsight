#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    if(s.length()==2) cout << s << endl;
    else{
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}