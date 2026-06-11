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
    int s;
    cin >> s;
    int m = s;
    vector<int> a(10000);
    a[m]+=1;
    rep(i,1000001){
        if(m%2==0){
            m/=2;
            a[m]+=1;
            if(a[m]==2){
                cout << i+2;
                return 0;
            }
        }
        else{
            m = 3*m + 1;
            a[m]+=1;
            if(a[m]==2){
                cout << i+2;
                return 0;
            }
        }
    }

    return 0;
}