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
    char X,Y;

    cin>>X>>Y;

    int x=X-'A',y=Y-'A';

    if(x>y){
        cout << ">"<<endl;
    }else if(x==y){
        cout<<"="<<endl;
    }else{
        cout<<"<"<<endl;
    }

    return 0;
}
