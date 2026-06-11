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
    int c1=0,c2=0;
    string s;
    cin >> s;
    rep(i,s.size()){
        if(i%2==0){
            if(s[i]!='0'){
                c1++;
            }
        }
        else{
            if(s[i]!='1'){
                c1++;
            }
        }
    }
    rep(i,s.size()){
        if(i%2==0){
            if(s[i]!='1'){
                c2++;
            }
        }
        else{
            if(s[i]!='0'){
                c2++;
            }
        }
    }
    cout << min(c1,c2);

    return 0;
}