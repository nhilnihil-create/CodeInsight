#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    long long ans=0;
    long long flag=0;
    for(int i=0;i<s.size();i++){
        if (s[i] == 'B') {
            flag++;
        }
        else {
            ans += flag;
        }
    }
    cout << ans;
}