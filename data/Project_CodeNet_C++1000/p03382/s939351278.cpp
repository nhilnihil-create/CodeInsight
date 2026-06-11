#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int did(int x,int y){
    return min(x,y-x);
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int mx=0;
    for (int i=1;i<=n;i++)
        cin>>a[i],mx=max(mx,a[i]);
    int s=a[1];
    for (int i=1;i<=n;i++)
        if (a[i]!=mx){
            s=a[i];
            break;
        }
    for (int i=1;i<=n;i++){
        if (did(s,mx)<did(a[i],mx))s=a[i];
    }
    cout<<mx<<' '<<s;
    return 0;
}