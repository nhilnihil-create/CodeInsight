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
    ll k;
    cin >> s >> k;
    ll cnt=0;
    string m;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') cnt++;
        else {
            m=s[i];
            break;
        }    
    }
    if(cnt>=k){
        cout << 1 << endl;
    }
    else{
        cout << m <<endl;
    }

    return 0;
}