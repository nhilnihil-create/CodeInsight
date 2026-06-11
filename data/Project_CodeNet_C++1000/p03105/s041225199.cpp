#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int ans=0;
    cin >> a >> b >> c ;
    if(b/a >= c){
        ans = c;
    }else{
        ans = b/a;
    }
    cout << ans;
    return 0;
}