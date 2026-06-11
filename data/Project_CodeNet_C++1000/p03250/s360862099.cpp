#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{

    int A,B,C;
    cin>>A>>B>>C;

    int MAX = max(A,max(B,C));
    
    cout << MAX*10 + A+B+C - MAX <<endl;

    return 0;
}
