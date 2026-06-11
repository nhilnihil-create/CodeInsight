#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <locale>
#include <iomanip>

#define nl '\n'

using namespace std;

long long a, b, c, x, y, s, t;

int main(){

    cin >> a >> b >> c >> x >> y;

    if(2*c >= (a+b)){
        cout << (a*x) + (b*y);
        return 0; 
    }

    s = min(x, y);
    if(s == x){
        t = t + (x*2*c);
        if(c*2 < b){
            t = t + (y-x)*c*2;
        } else{
            t = t + (y-x)*b;
        }
    }else if(s == y){
        t = t + (y*2*c);
        if(c*2 < a){
            t = t + (x-y)*c*2;
        } else{
            t = t + (x-y)*a;
        }
    }

    cout << t;

    







}

//g++ -std=c++14 comp.cpp -o b; ./b.exe