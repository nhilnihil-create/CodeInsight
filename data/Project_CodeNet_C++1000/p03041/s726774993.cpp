#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){

    int n,k;
    string s = "";

    cin >> n >> k;
    cin >> s;

    if(s[k-1] == 'A'){
        s[k-1] = 'a';
    }
    if(s[k-1] == 'B'){
        s[k-1] = 'b';
    }
    if(s[k-1] == 'C'){
        s[k-1] = 'c';
    }

    cout << s << endl;


}