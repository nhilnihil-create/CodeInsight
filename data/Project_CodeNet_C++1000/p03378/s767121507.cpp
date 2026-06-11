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
    int a,b,c;
    cin >> a >> b >> c;
    int cnt1=0,cnt2=0;
    rep(i,b){
        int m;
        cin >> m;
        if(m<c){
            cnt1+=1;
        }
        else if(m>c){
            cnt2+=1;
        }
    }
    cout << min (cnt1,cnt2);

    return 0;
}