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

    int N,M,X,Y,x,y,mx,my;

    cin>>N>>M>>X>>Y;

    mx=X;
    my=Y;


    for(int i=1;i<=N;i++){
        cin>>x;
        mx=max(mx,x);
    }

    for(int i=1;i<=M;i++){
        cin>>y;
        my=min(my,y);
    }

    if(mx<my){
        cout << "No War" <<endl;
    }else{
        cout << "War" <<endl;
    }

    return 0;
}
