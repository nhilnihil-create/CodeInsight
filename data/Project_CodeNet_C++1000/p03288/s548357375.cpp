#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    string ans="AGC";
    cin>>n;
    if(n<1200)ans="ABC";
    else if(n<2800)ans="ARC";
    else ans="AGC";
    cout<<ans<<endl;
}
