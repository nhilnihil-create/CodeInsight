#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    int size, num = 0;
    cin >> size >> s;
    for(int i = 0;i < size;i++){
        if(s[i] == 'R')++num;
    }
    if(num > (size - num))cout << "Yes";
    else cout << "No";
}