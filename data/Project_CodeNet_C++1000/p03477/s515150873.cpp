#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,D,i,j;
    
    cin >> A >> B >> C >> D;
    
    i = A + B;
    j = C + D;
    
    if(i > j)cout << "Left" << endl;
    if(i == j)cout << "Balanced" << endl;
    if(i < j)cout << "Right" << endl;
}