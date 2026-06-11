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
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;





int main()
{
    
  
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = c + (-d + b), y = d + (c - a);;
    cout << x << " " << y << " ";
    int g = x + (-y + d), f = y + (x - c);
    cout << g << " " << f << endl;

    return 0;

}