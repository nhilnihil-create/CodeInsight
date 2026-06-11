#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c,d;
    string ans;
    cin >>a>>b>>c>>d;

    if(a+b>c+d)ans="Left";
    else if(a+b<c+d)ans="Right";
    else ans="Balanced";

    cout<<ans<<endl;
}
