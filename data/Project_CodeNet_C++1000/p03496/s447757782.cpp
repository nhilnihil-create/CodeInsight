#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int Abs(int n){
    if(n<0)return -n;
    else return n;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int MAX=0,pos=0;
    for(int i=0;i<n;i++){
        if(Abs(MAX)<Abs(a[i])){
            MAX=a[i];
            pos=i;
        }
    }
    cout<<2*n-1<<endl;
    for(int i=0;i<n;i++)cout<<pos+1<<" "<<i+1<<endl;
    if(MAX>0){
        for(int i=0;i<n-1;i++)cout<<i+1<<" "<<i+2<<endl;
    }
    else{
        for(int i=n-2;i>=0;i--)cout<<i+2<<" "<<i+1<<endl;
    }

}