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
    int a,b;
    string ans;
    cin >> a >> b;
    int c = a*b;
    if (c%2 == 0) ans = "Even";
    else ans = "Odd";
    print(ans);
    
    
    return 0;
}
