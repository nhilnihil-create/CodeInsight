#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int a;
    cin >> a;
    if(a < 1200){
        cout << "ABC";
    }
    else if(a < 2800){
        cout << "ARC";
    }
    else
    {
        cout << "AGC";
    }
    
    cout << endl;
}
