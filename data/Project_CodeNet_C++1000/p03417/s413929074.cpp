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
    long long n, m;
    cin >> n >> m;
    long long ans;
    if (n >= 3 && m >= 3) ans = (n - 2) * (m - 2);
    else if (n == 2 && m>=2|| m == 2 && n>=2) ans = 0;
    else if (n ==1 && m>=2|| m ==1 && n>=2) ans = (n==1)?m-2:n-2;
    else if (n==1 && m==1) ans=1;
    cout << ans << endl;
}


            
