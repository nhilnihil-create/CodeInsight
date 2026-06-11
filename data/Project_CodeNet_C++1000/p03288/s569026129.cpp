#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;

    if(N < 1200)
        cout << "ABC" << endl;
    else if(N < 2800)
        cout << "ARC" << endl;
    else
        cout << "AGC" << endl;

} 