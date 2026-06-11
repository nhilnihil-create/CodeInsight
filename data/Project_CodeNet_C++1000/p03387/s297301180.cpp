#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int M = max(max(A, B), C);
    if((3 * M) % 2 == (A + B + C) % 2){
        cout << ((3 * M) - (A + B + C)) / 2 << endl;
    }
    else{
        cout << ((3 * M + 3) - (A + B + C)) / 2 << endl;
    }
    return 0;
}