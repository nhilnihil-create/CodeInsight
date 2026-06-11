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
    cin >> a >> b >>c;
    if(b-a+1<=2*c){
        for(int i=a;i<b+1;i++){
            cout << i << endl;
        }
    }
    else{
        for(int i=a;i<a+c;i++){
            cout << i << endl;
        }
        for(int j=b-c+1;j<b+1;j++){
            cout << j << endl;
        }
    }

    return 0;
}