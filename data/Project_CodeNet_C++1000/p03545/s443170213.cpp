#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int a = s.at(0) - '0';
    int b = s.at(1) - '0';
    int c = s.at(2) - '0';
    int d = s.at(3) - '0';
    
    if(a+b+c+d == 7){
        printf("%d+%d+%d+%d=7\n", a, b, c, d);
    }else if(a+b+c-d==7){
        printf("%d+%d+%d-%d=7\n", a, b, c, d);
    }else if(a+b-c+d==7){
        printf("%d+%d-%d+%d=7\n", a, b, c, d);
    }else if(a-b+c+d==7){
        printf("%d-%d+%d+%d=7\n", a, b, c, d);
    }else if(a+b-c-d==7){
        printf("%d+%d-%d-%d=7\n", a, b, c, d);
    }else if(a-b-c+d==7){
        printf("%d-%d-%d+%d=7\n", a, b, c, d);
    }else if(a-b+c-d==7){
        printf("%d-%d+%d-%d=7\n", a, b, c, d);
    }else if(a-b-c-d==7){
        printf("%d-%d-%d-%d=7\n", a, b, c, d);
    }
    return 0;
}