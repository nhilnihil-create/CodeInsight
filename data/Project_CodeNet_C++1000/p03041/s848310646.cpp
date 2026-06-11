#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n>>k;
    string s;
    cin >> s;
    for(int i =0; i<s.size(); i++){
        if(i==k-1){
            putchar(tolower(s[i]));
        }else{
           cout << s[i]; 
        }
    }
}