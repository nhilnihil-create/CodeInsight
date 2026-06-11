#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[30];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    if(s.length() < 26){
        for(int i = 0;i < s.length();i++){
            vis[s[i] - 'a'] = true;
        } 
        for(int i = 0;i < 26;i++){
            if(!vis[i]){
                s = s + (char)('a' + i);
                cout << s << endl;
                break;
            }
        }
    }else{
        int len = s.length();
        for(int i = len - 2;i >= 0;i--){
            int id = -1;
            for(int j = i + 1;j < len;j++){
                if(s[j] > s[i]){
                    if(id == -1){
                        id = j;
                    }else{
                        if(s[j] < s[id]){
                            id = j;
                        }
                    }
                }
            } 
            if(id != -1){
                swap(s[i], s[id]);
                s = s.substr(0, i + 1);
                cout << s << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}
