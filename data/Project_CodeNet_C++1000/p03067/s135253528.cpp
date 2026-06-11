#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int a,b,c; cin >> a >> b >> c;
    string ans = "No";
    if(a > b){
        if(b < c && c < a) ans = "Yes";
    }else{
        if(a < c && c < b) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}