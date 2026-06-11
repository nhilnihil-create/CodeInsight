#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin>>s;
    if(s=="111")s="999";
    else if(s=="119")s="991";
    else if(s=="191")s="919";
    else if(s=="199")s="911";
    else if(s=="911")s="199";
    else if(s=="919")s="191";
    else if(s=="991")s="119";
    else if(s=="999")s="111";
    cout<<s<<endl;

    return 0;
}
