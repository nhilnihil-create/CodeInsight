#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    int n=100000;
    int p[100005];
    int a[100005];
    int s[100005];
    p[1]=0;
    p[2]=1;
    for(int i=3; i<=n; i +=2){
        p[i]=1;
        p[i+1]=0;
        for(int j=3; j*j<=i; j+=2){
            if(p[j]==1 & i%j == 0){
                p[i]=0;
                break;
            }
        }
    }
    a[1]=0;
    a[2]=0;
    for(int i=3; i<=n; i +=2){
        if(p[i]==1 & p[(i+1)/2]==1) a[i]=1;
        else a[i]=0;
        a[i+1]=0;
    }
    s[1]=0;
    for(int i=2; i<=n; i +=1){
        s[i] = s[i-1]+a[i];
    }

    for(int i=0; i<q; i++){
        int x,y;
        cin >> x >> y;
        cout << s[y]-s[x-1] << endl;
    }
}