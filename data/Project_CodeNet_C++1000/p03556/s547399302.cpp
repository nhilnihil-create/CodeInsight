#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int s = 1;
    int ans =1;
    while(true){
        ans = s*s;
        s++;
        if(n<s*s) break;
    }
    cout << ans << endl;
}