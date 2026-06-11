#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    char x,y;
    cin >> x >> y;
    char ans;
    if(x == y){
        ans = '=';
    } else if(x > y){
        ans = '>';
    } else { 
        ans = '<';
    }
    cout << ans << endl;

}
