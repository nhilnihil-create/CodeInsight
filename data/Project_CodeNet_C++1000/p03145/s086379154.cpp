#include <bits/stdc++.h>

using namespace std;

int main(){
    int A,B,C,S,areaTriangle;
    cin>>A>>B>>C;
    S=(A+B+C)/2;
    areaTriangle=sqrt(S*(S-A)*(S-B)*(S-C));
    cout<<areaTriangle;
}

