#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B,C,times;
    cin >> A >> B >> C;
    
    times = B/A;
    if(times > C) times = C;
    cout << times << endl;
    return 0;
}