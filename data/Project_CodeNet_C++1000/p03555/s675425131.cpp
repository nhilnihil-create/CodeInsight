#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {

    char n[2][3];
    cin>>n[0];
    cin>>n[1];
    if(n[0][0]==n[1][2]&&n[0][1]==n[1][1]&&n[0][2]==n[1][0])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
