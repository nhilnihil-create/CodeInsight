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
    vector<long long int>a(n), b(n);

    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    long long int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        x += b[i] - a[i];
    }
    long long int r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])r += a[i] - b[i];
        else if (a[i] < b[i])r -= (b[i] - a[i]) / 2;
    }
    if (r<=0)cout << "Yes" << endl;
    else cout << "No" << endl;



    return 0;

}