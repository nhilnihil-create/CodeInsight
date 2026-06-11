#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0,front=0,back=s.size()-1;
    while(front<=back){
        if(s[front]!=s[back]){
            if(s[front]=='x'){
                ans++;
                front++;
            }else if(s[back]=='x'){
                ans++;
                back--;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else{
            front++;
            back--;
        }
    }

    cout << ans << endl;
}