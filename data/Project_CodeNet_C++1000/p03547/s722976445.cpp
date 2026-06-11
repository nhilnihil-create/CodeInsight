#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    char ans;
    if (a < b){
        ans = '<';
    }else if (a > b){
        ans = '>';
    }else{
        ans = '=';
    }

    cout << ans << endl;
}