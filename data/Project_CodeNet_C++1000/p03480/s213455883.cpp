#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = 0;
    int idx = 0;
    while(s[idx] != 0){
        n++;
        idx++;
    }
    // printf("%d\n", n);
    int ans = 0;
    if (n % 2 == 0){
        char num = s[n / 2 - 1];
        for(int i = 0; i < n / 2; i++){
            if(s[n / 2 + i] == num && s[n / 2 - i - 1] == num) ans++;
            else break;
        } 
        ans += n / 2;
    } else{
        char num = s[n / 2];
        for(int i = 0; i < n / 2; i++){
            if(s[n / 2 + i + 1] == num && s[n / 2 - i - 1] == num) ans++;
            else break;
        }

        ans += n / 2 + 1;
    }
    printf("%d\n", ans);
}