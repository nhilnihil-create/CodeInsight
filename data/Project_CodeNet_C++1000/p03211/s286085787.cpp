#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans = 10000;
    rep(i,0,s.length()-3){
        string c;
        c = s[i]; 
        c += s[i+1];
        c += s[i+2];
        int num = atoi(c.c_str());
        num = num - 753;
        if(ans > abs(num)) ans = abs(num);
    }
    cout<<ans<<endl;
    return 0;
}