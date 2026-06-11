#include<bits/stdc++.h>
using namespace std;
int main(){
    char x,y;
    cin >> x >> y;
    if((int)(x-y)>0)cout << ">";
    else if((int)(x-y)<0)cout << "<";
    else cout << "=";
}