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
    int n;
    cin >> n;
    int x[101],y[101],h[101];
    int x1[101]={},y1[101]={};
    rep(i,n) {
        cin >> x[i] >> y[i] >> h[i];
        x1[x[i]] = 1;
        y1[y[i]] = 1;
    }
    int a=x[0],b=y[0],c=0;
    rep(i,n){
        if(h[i]!=0){
            a = x[i];
            b = y[i];
            c = h[i];
            break;
        }
    }
    // if(c==0){
        // int t,u;
        // rep(i,101){
        //     if(x1[i]!=1){
        //         t = i;
        //     }
        //     if(y1[i]!=1){
        //         u = i;
        //     }
        // }
    //     cout << t << " " << u << " " << 1 << endl;
    //     return 0;

    // }


    rep(i,101){
        rep(j,101){
            // cout << i << " " << j << endl; 
            int p,q;
            if(a==i) p = 0;
            else p = abs(i-a);
            if(b==j) q = 0;
            else q = abs(j-b);
            int H = p + q + c;
            bool flag = false;
            rep(k,n){
                int p1,q1;
                if(x[k]==i) p1 = 0;
                else p1 = abs(i-x[k]);
                if(y[k]==j) q1 = 0;
                else q1 = abs(j-y[k]);
                int H1 = p1 + q1 + h[k];
                if(h[k]!=0){
                    if(H1!=H){
                        flag = true;
                        break;
                    } 
                }
            }
            rep(k,n){
                if(h[k]==0){
                    int tmp = abs(i-x[k]) + abs(j-y[k]);
                    if(H>tmp){
                        flag = true;
                    }
                }
            }
            if(!flag){
                cout << i << " " << j << " " << H << endl; 
                return 0;
            }
        }
    }

    return 0;
}