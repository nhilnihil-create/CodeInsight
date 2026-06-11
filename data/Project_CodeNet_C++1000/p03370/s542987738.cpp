#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> m(n);
    for(int i=0;i<n;i++)
    cin>>m[i];
    int64_t min=100001,sum=0;
    for(int i=0;i<n;i++){
        if(min>m[i])
        min=m[i];
        sum+=m[i];
    }
    x-=sum;
    cout<<n+x/min<<endl;
}