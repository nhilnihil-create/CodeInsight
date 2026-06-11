#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>
#include <iomanip>
#define input(a) cin >> a
#define print(x) cout << x << endl
#define rep(a,n) for(int i = a; i < n; i++)
#define ll long long int
using namespace std;


int main(){
    int n,a;
    string ans;
    input(n);
    input(a);
    int ex = n%500;
    if (ex <= a) ans = "Yes";
    else ans = "No";
    print(ans);

    return 0;
}
