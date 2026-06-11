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
    int A[3]={},dsum;

    cin>>A[0]>>A[1]>>A[2];

    sort(A,A+3);

    
    cout<<abs(A[2]-A[1])+abs(A[1]-A[0])<<endl;

    return 0;
}
