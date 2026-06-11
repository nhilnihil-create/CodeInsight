#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

int n,q;
char s[200010],t[200010],d[200010];

bool is_vnz(int i){
    int p=i;
    for (int j=0;j<q;j++){
        if(s[p]==t[j]&&d[j]=='L'){
            if(p==1) return 1;
            else p--;
        } else if(s[p]==t[j]&&d[j]=='R'){
            if(p==n) return 0;
            else p++;
        }
    }
    return 0;
}

bool is_vnn(int i){
    int p=i;
    for (int j=0;j<q;j++){
        if(s[p]==t[j]&&d[j]=='L'){
            if(p==0) return 0;
            else p--;
        } else if(s[p]==t[j]&&d[j]=='R'){
            if(p==n) return 1;
            else p++;
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>q;
    s[0]='_';
    for(int i=1;i<=n;i++) cin>>s[i];
    s[n+1]='_';
    for(int i=0;i<q;i++) cin>>t[i]>>d[i];
    
    int ll=0,lr=n+1,rl=0,rr=n+1;
    while(lr-ll!=1){
        int m=(ll+lr)/2;
        if(is_vnz(m)) ll=m;
        else lr=m;
    }
    while(rr-rl!=1){
        int m=(rl+rr)/2;
        if(is_vnn(m)) rr=m;
        else rl=m;
    }
    
    cout<<rr-ll-1<<endl;
}