#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a ;
    int s_1 , s_2 , s_3;
    s_1 = (a-(a%100))/100;
    s_2 = (a - 100* s_1 - (a - 100* s_1)%10)/10;
    s_3 = (a - 100* s_1)%10;
    cout << s_1+s_2+s_3;
}