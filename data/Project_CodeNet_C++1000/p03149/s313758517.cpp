#include <bits/stdc++.h>
using namespace std;

int d[9];

int main(){
    int in;
    
    for(int i=0; i<4; ++i){
        cin >> in;
        d[in] ++;
    }

    if(d[7] == 1 && d[1] == 1 && d[9] == 1 && d[4] == 1)
        cout << "YES";
    else
        cout << "NO";
}