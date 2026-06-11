#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,b;
    cin>>a;
    if(a < 1200 ){
        cout<<"ABC";
    }
    else if(a < 2800){
        cout<<"ARC";
    }
    else{
        cout<<"AGC";
    }

    return 0;
}
