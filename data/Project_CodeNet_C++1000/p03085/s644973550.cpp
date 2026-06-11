#include <bits/stdc++.h>
using namespace std;

int main(){
    char t[8] = "ACTGAC";
    char b;
    cin >> b;
    for(int i=0;i<4;i++){
        if(b==t[i]){
            cout << t[i+2];
            return 0;
        }
    }
    cout << "error";
    return 0;
}