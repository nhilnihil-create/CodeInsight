#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    int a[m];
    int cnt1=0,cnt2=0;
    for(int i=0;i<m;i++){
        cin>>a[i];
        if(a[i]<x)cnt1++;
        else cnt2++;
    }
    if(cnt1>cnt2)cout<<cnt2<<endl;
    else cout<<cnt1<<endl;
    return 0;
}