#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<cmath>
#include<vector>
#include<map>
#include<random>
#include<sstream>
using namespace std;

int main(){
    int n;cin >> n ;
    int t,h,o;
    t = n/100;
    h = n%100/10;
    o = n%10;
    //cout << t << h <<  o << endl;
    if(t == 1)t = 9;
    else if(t==9)t = 1;

    if(h == 1)h = 9;
    else if(h==9)h = 1;
 
    if(o == 1)o = 9;
    else if(o==9)o = 1;
    cout << t*100 + h*10 + o << endl;
    

}
