#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100003
using namespace std;

int main(){
    string s;
    int ans,l;
    cin>>s;
    l = ans = s.size();
    for(int i=1;i<l;i++){
        if(s[i]==s[i-1]) continue;
        ans = min(ans,max(i,l-i));
    }
    printf("%d",ans);
    return 0;
}