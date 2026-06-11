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
    int c[1000],s[1000],f[1000];

    rep(i,n-1){
        cin >> c[i] >> s[i] >> f[i];
    }

    rep(i,n-1){
        int cnt =0;
        for(int j=i;j<n-1;j++){
            if(j==i){
                cnt+=c[j]+s[j];
            }
            else{
                if(cnt<=s[j]){
                    cnt = s[j];
                    cnt += c[j];
                }
                else{
                    int m;
                    m = cnt -s[j];
                    m %= f[j];
                    if(m==0){
                        cnt += c[j];
                    }
                    else{
                        cnt += f[j] - m;
                        cnt += c[j];
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    cout << 0 << endl;

    return 0;
}