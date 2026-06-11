#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n=s.size();
    int cnt=0;
    if(s[0]=='A'){
        for(int i=2;i<n-1;i++){
            if(s[i]=='C'){
                cnt+=1;
            }
        }
        if(cnt!=1){
            cout << "WA";
            return 0;
        }
    }
    else{
        cout << "WA";
        return 0;
    }
     
    rep(i,n){
        bool frag = false;
        if(s[i]=='A'||s[i]=='C'){
            continue;
        }
        else {
            for(char q='a';q<='z';q++){
                if(s[i]==q){
                    frag = true;
                    break;
                }
            }
            if(frag){
                continue ;
            }
            else{
                cout << "WA";
                return 0;
            }
        }
    }
    cout << "AC";

    return 0;
}