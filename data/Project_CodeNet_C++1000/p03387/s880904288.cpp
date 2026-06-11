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
    int cnt=0;
    int a,b,c;
    cin >> a >> b >> c;
    if(a<b){
        swap(a,b);
    }
    if(b<c){
        swap(b,c);
    }
    if(a<b){
        swap(a,b);
    }

    if(b%2!=c%2){
        cnt+=1;
        a+=1;
        c+=1;
    }
    cnt+=(b-c)/2;
    cnt+=a-b;
    cout << cnt;


    return 0;
}