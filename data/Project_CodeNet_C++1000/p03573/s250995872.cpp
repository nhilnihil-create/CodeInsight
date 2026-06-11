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

    if(A==B){
        cout <<C<<endl;
        return 0;
    }
    if(B==C){
        cout<<A<<endl;
        return 0;
    }
    if(A==C){
        cout<<B<<endl;
        return 0;
    }

    return 0;
}
