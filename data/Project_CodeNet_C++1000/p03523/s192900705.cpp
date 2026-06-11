#include <bits/stdc++.h>
using namespace std;
int pos[]={0,4,6,8};
string s("AKIHABARA"),t,x;
int del[55]; 
int main() {
    cin>>x;
    for(int i=0;i<(1<<4);i++) {
        memset(del,0,sizeof(del));
        t.clear(); 
        for(int j=0;j<4;j++) {
            if(i>>j&1) del[pos[j]] = true;   
        }
        for(int j=0;j<s.size();j++) {
            if(del[j]) continue;
            else t.push_back(s[j]);
        }
        if(x==t) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}