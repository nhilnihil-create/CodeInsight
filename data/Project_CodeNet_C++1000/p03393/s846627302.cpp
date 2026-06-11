#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    int che[26];
    for(int i = 0; i < 26; i++){
        che[i] = 0;
    }
    for(int i = 0; i < n; i++){
        che[s[i] - 97]++;
    }

    string ans;
    if(n == 26){
        int flag = -1;
        for(int i = 25; i > 0; i--){
            if(s[i] > s[i - 1]){
                flag = i - 1;
                che[s[i] - 97]++;
                break;
            }else{
                che[s[i] - 97]++;
            }
        }


        if(flag == -1){
            cout << -1 << endl;
        }else{
            for(int i = 0; i < flag; i++){
                ans += s[i];
            }
            
            for(int i = 0; i < 26; i++){
                if(che[i] == 2 && s[flag] < char(97 + i)){
                    ans += char(97 + i);
                    break;
                }
            }
            cout << ans << endl;
        }
    }else{
        ans = s;
        for(int i = 0; i < 26; i++){
            if(che[i] == 0){
                ans += (char)(97 + i);
                break;
            }
        }   

        cout << ans << endl;
    }
}