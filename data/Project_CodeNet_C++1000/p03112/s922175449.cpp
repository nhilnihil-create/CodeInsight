#include <bits/stdc++.h>
using namespace std;

long long int s[100005],t[100005];
int lower_s(int start,int end,long long int x){
    while(end-start>1){
        if(s[(start+end)/2]<x)start=(start+end)/2;
        else end=(start+end)/2;
    }
    return end;
}
int lower_t(int start,int end,long long int x){
    while(end-start>1){
        if(t[(start+end)/2]<x)start=(start+end)/2;
        else end=(start+end)/2;
    }
    return end;
}

int main(){
    int a,b,q;
    cin >> a >> b >> q;
    long long int x;
    long long int ans=1e15;
    int tmp1,tmp2;
    for(int i=0;i<a;i++)cin >> s[i];
    for(int j=0;j<b;j++)cin >> t[j];
    for(int i=0;i<q;i++){
        ans=1e15;
        cin >> x;
        tmp1=lower_s(0,a-1,x);
        tmp2=lower_t(0,b-1,x);
        for(int i=max(tmp1-1,0);i<=tmp1;i++){
            for(int j=max(tmp2-1,0);j<=tmp2;j++){
                ans=min(ans,abs(s[i]-x)+abs(s[i]-t[j]));
                ans=min(ans,abs(t[j]-x)+abs(s[i]-t[j]));
            }
        }
        cout << ans << endl;
    }
}