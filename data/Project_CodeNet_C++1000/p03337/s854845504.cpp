#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b;
    cin>>a>>b;
    int s[3];
    s[0]=a+b;
    s[1]=a-b;
    s[2]=a*b;
    sort(s,s+3);
    cout<<s[2]<<endl;
}
