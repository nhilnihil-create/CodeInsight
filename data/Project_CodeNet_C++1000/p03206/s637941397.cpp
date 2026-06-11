#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int d;cin>>d;
    if(d==25)cout<<"Christmas";
    if(d == 24)cout<<"Christmas Eve";
    if(d == 23)cout<<"Christmas Eve Eve";
    if(d == 22)cout<<"Christmas Eve Eve Eve";
    return 0;
}