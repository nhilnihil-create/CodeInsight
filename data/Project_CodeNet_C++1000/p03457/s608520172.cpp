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

    int time=0,xn=0,yn=0;
    int n;
    cin >> n;
    rep(i,n){
        int t,x,y;
        cin >> t >> x >> y;
        if(abs(x-xn)+abs(y-yn)>t-time){
            cout << "No" << endl;
            return 0;
        }
        else{
            if((t-time-abs(x-xn)-abs(y-yn))%2!=0){
                cout << "No";
                return 0;
            }
            else{
                time = t;
                xn = x;
                yn = y;
            }
        }
    }

    cout << "Yes";

    return 0;
}