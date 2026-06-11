#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c; cin>>a>>b>>c;
    int ans=0;
    if(a+b<c){
        ans = a+b+b+1;
    }
    else ans = b+c;
    cout << ans << endl;
}