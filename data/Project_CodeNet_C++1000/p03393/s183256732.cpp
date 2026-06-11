#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
string alphabet="abcdefghijklmnopqrstuvwxyz";
int main() {
    string s;
    cin>>s;
    if(s.size() != 26){
        cout << s;
        rep(i , 26){
            if(count(s.begin() , s.end() , alphabet[i]) == 0){
                cout << alphabet[i];
                break;
            }
        }
    }
    else{
        if(s == "zyxwvutsrqponmlkjihgfedcba"){
            cout<<-1;
        }
        else{
        rep(i , 25){
            if(s[25 - i] > s[24 - i]){
                rep(j , 24 - i){
                    cout<<s[j];
                }
                    for(int j = 25; j >= 25 - i; j--){
                        if(s[j] > s[24 - i]){
                            cout << s[j];
                            break;
                            }
                    }
                    break;
                }
            }
        }
    }
 
}