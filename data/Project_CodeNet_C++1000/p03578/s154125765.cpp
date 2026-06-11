#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>

//#include<bits/stdc++.h>


using namespace std;



int main()
{
    
    int n, m;
    cin >> n;
    map<int, int>a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    cin >> m;
    bool f = 0;
    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        a[x]--;
        if (a[x] < 0)f = 1;
    }

    if (f)cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;

}