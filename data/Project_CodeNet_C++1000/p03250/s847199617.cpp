#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c;
    cin>>a>>b>>c;
    int aaa[3] = {a,b,c};
    sort(aaa,aaa+3);
    cout<<aaa[2]*10+aaa[1]+aaa[0]<<endl;
    }
