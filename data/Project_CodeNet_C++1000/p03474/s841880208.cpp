#include <iostream>
using namespace std;
int main(){
    int a, b;
    string s;
    cin >> a >> b >> s;
    for(int i=0; i<a; i++){
        if(s[i]=='-'){
            puts("No");
            return 0;
        }
    }
    if(s[a]!='-'){
        puts("No");
        return 0;
    }
    for(int i=a+1; i<a+b; i++){
        if(s[i]=='-'){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}