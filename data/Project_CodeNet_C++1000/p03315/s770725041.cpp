#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n=0;
    for(char c:s){
        if(c=='+'){
            n++;
        }else{
            n--;
        }
    }
    cout << n << endl;
}
