#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int a,b,c;cin >> a >> b >> c;
    int m = 0;
    if(a >= b && a >= c)m += a*10+b+c;
    else if(b >= a && b >= c)m+= b*10+a+c;
    else if(c>=a && c >= b)  m+= c*10+a+b;
    cout << m << endl;
}