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
#define input(x) cin >> x
#define print(x) cout << x << endl
#define rep(n) for(int i = a; i < n; i++)
#define ll long long int
using namespace std;

int main(){
    string s;
    input(s);
    //s.at(3) = "8";
    s.replace(0,4,"2018");
    print(s);
    return 0;
}
