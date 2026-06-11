#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
int n;
string S;
int check(int x){
    string s = S;
    int len = 0;
    for(int i = 1; i <= n; i++){
        if(len){
            len--;
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
        if(s[i] == '1'){
            if(i - 1 < x){
                if(n - i < x){
                    len = x - 1;
                }
            }
        }
    }
    if(len) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>S; S = " " + S;
    n = S.size() - 1;
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r + 1)>>1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l;
    return 0;
}