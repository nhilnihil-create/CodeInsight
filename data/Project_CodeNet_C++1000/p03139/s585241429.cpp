#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int ans=min(a,b);
    int mans=max(a+b-n,0);
    cout<<ans<<" "<<mans<<endl;
}