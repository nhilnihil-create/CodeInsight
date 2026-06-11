#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A,B,p1,p2;

    cin >> N >> A >> B;
    
    p1 = N * A; p2 = B;
    if(p1 > p2)
        cout << p2 << endl;
    else
        cout << p1 << endl;
}