#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ai=a[n-1];
    int index=lower_bound(a,a+n,ai/2)-a;
    if(a[index]==ai/2){
        cout<<ai<<" "<<a[index]<<endl;
        return 0;
    }
    if(a[index]<ai && a[index-1]<=ai-a[index]){
        cout<<ai<<" "<<a[index]<<endl;
    }
    else{
        cout<<ai<<" "<<a[index-1]<<endl;
    }
    return 0;
}