#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    char x,y;
    cin >> x >> y;
    if(x < y) puts("<");
    else if(x == y) puts("=");
    else puts(">");
}