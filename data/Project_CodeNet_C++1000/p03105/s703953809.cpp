#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;

map<int, bool> check;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b / a > c) cout << c << endl;
    else cout << b / a << endl;

    return 0;
}