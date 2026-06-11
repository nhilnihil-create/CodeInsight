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
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<int>x, y, z;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if (d <= a)x.push_back(d);
        else if (d > b)z.push_back(d);
        else y.push_back(d);

    }

    cout << min(x.size(), min(y.size(), z.size()));


    return 0;

}