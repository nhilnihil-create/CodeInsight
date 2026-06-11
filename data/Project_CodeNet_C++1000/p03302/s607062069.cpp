#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define pb push_back 
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<30)
#define MOD 1000000007
using ll = long long;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a + b == 15)cout << '+';
    else if (a*b == 15)cout << '*';
    else cout << 'x';
    return 0;
}
