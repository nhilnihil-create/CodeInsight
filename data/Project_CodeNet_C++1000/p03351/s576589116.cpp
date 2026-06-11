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
    int a,b,c,d;
    cin>> a >> b >> c >> d;
    if(abs(a-c)<=d){
        cout << "Yes" << endl;
        return 0;
    }


    if(abs(a-b)<=d&&abs(b-c)<=d){
        cout << "Yes" << endl;
        return 0;
    }
    else{
        cout << "No" << endl;
        return 0;
    }


    return 0;
}
