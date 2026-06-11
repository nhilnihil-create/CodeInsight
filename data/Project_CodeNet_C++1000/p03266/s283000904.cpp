#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include<map>
#include<set>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long ans;
    if (k % 2 == 1) ans= pow(n/k,3);
    else ans=pow(n / (k / 2)-n/k , 3)+pow(n/k,3);
    cout << ans << endl;
}
    