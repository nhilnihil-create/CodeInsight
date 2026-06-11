#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,hantei = 0;
    cin >> a >> b;
    char s[a+b+1];
    cin >> s;
    for(long long i=0;i<a;i++){
        if(s[i] == '-'){
            hantei = 1;
            break;
        }
    }
    if(s[a] != '-') hantei = 1;
    for(int i=a+1;i<a+b;i++){
        if(s[i] == '-'){
            hantei = 1;
            break;
        }
    }
    if(hantei == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}