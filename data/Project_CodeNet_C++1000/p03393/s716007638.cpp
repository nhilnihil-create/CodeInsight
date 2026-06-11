// AGC 022 A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    string s; cin >> s;
    int len = s.length();
    int ch[26];
    for(int i = 0; i < 26; i++) ch[i] = 0;
    for(int i = 0; i < len; i++){
        ch[s[i]-'a']++;
    }
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    if(len < 26){
        cout << s;
        for(int i = 0; i < 26; i++){
            if(ch[i] == 0){
                cout << (char)(i+'a') << endl;
                return 0;
            }
        }
    }else{
        int i = 25;
        for(i = 25; i > 0; i--){
            ch[s[i]-'a']--;
            if(s[i] > s[i-1]){
                break;
            }
        }
        for(int j = 0; j < i-1; j++) cout << s[j];
        for(int k = 0; k < 26; k++){
            if(ch[k] == 0 && s[i-1] < 'a'+k){
                cout << (char)(k+'a') << endl;  
                return 0;
            }
        }
    }
    return 0;
}