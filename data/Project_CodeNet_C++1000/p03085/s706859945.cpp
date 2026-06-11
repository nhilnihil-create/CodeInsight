#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    char s;
    cin >> s;
    if(s == 'T'){
        cout << 'A';
    } 
    else if(s == 'G'){
        cout << 'C';
    }
    else if(s == 'C'){
        cout << 'G';
    }
    else{
        cout << 'T';
    }
    cout << endl;
}
