#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c;
    string ans="";
    cin >>a>>b>>c;
    if(a+b>=c)ans="Yes";
    else ans="No";
    cout<<ans<<endl;
}
