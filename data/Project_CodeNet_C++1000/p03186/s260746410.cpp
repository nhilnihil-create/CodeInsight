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

long long a, b, c;
 
int main(){
    cin >> a >> b >> c;

    if((a+b) == c){
        cout << b+c;
    } else if((a+b) < c){
        cout << (a+b) + b + 1;
    } else if((a+b) > c){
        cout << b+c;
    }
 
 
 
 
}

//g++ -std=c++14 comp.cpp -o b; ./b.exe