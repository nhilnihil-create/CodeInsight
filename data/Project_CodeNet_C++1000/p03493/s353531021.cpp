#include <bits/stdc++.h>
using namespace std;

int main(){
    int S;
    int block = 0;
    cin >> S;
    for(int i = 0; i < 3; i++){
        if(S % 10 != 0){
            block++;
        }
        S /= 10;
    }
    cout << block << endl;
}