#include <bits/stdc++.h>

using namespace std;

int main(){

    float a,b,c;
    
    cin>>a>>b>>c;

    float h = a*b;

    h = h/c;

    float area = (c*h)/2;

    cout<<area;

    return 0;
}