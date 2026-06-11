#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int n;
    cin>>n;
    vector<int> a(n+2);
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=0;
    int s=0;
    rep(i,n+1){
        s +=abs(a[i+1]-a[i]);
    }
    //cout<<s<<endl;
    for(int i=1;i<=n;i++){
        if(a[i]>=a[i-1]&&a[i]<=a[i+1]){
            cout<<s<<endl;
        }
        else if(a[i]<=a[i-1]&&a[i]>=a[i+1]){
            cout<<s<<endl;
        }
        else if(a[i]>=a[i-1]){
            cout<<s-2*abs(a[i]-max(a[i-1],a[i+1]))<<endl;
        }
        else{
            cout<<s-2*abs(a[i]-min(a[i-1],a[i+1]))<<endl;
        }

    }
}