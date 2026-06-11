#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int n=0;
    string s;
    cin >> s;
    
    for(int i=0;i<3;i++){
        if(s[i] == 'o') n++;
    }
    
    cout << 700 + n * 100 <<endl;
}