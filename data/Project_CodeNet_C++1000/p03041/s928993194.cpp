#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    double n,k; cin >> n >> k;
    string s; cin >> s;
    s[k-1] = tolower(s[k-1], locale());
    cout << s << endl;
}