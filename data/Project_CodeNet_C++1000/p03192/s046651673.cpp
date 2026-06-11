#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    int ans = 0;
    if(a/1000 == 2)++ans;
    if((a%1000)/100 == 2)++ans;
    if( (((a%1000)%100)/10) == 2)++ans;
    if( (((a%1000)%100)%10) == 2)++ans;
    cout << ans << endl;
}