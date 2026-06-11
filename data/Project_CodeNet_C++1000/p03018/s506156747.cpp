#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int bc = 0;
    long ans = 0;
    int n = s.length();
    for(int i=n-1;i>=0;i--){
        if(s[i]=='A'){
            ans += bc;
        }else if(s[i]=='B')bc = 0;
        else{
            if(i!=0 && s[i-1]=='B'){
                bc++;
                i--;
            }else bc = 0;
        }
    }
    cout<<ans<<endl;
}