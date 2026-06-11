#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;

int main(void) {
    int a,b,c; cin >> a >> b >> c;
    int diffA,diffB,diffC;
    diffA = abs(a-b);
    diffB = abs(b-c);
    diffC = abs(c-a);
    cout << (diffA + diffB + diffC - max(max(diffA,diffB),diffC)) << endl;
}