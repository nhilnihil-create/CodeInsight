#include<bits/stdc++.h>
using namespace std;

int main(void){

    string str;
    cin >> str;
    int a = 0, b = 0, c = 0;
    int l = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a') a++;
        if(str[i] == 'b') b++;
        if(str[i] == 'c') c++;
    }
    l = a + b + c;
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    if(a < c){
        int temp = a;
        a = c;
        c = temp;
    }
    if(b < c){
        int temp = b;
        b = c;
        c = temp;
    }
    
    a -= l/3;
    b -= l/3;
    c -= l/3;
    if(l % 3 == 1){
        a--;
    }else if(l % 3 == 2){
        a--;
        b--;
    }
    if(a == 0 && b == 0 && c == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
