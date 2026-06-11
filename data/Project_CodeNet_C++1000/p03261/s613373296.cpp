#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,hantei = 0;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i] == s[j]){
                hantei = 1;
                break;
            }
        }
    }
    for(int i=1;i<n;i++){
        int x =s[i-1].length();
        if(s[i-1][x-1]!=*s[i].begin()){
            hantei = 1;
            break;
        }
    }
    if(hantei == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
}