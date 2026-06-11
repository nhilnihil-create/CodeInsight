#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long a,b,c,k;
    cin>>a>>b>>c>>k;
    if(k%2==1){
        cout<<b-a<<endl;
    }
    else{
        cout<<a-b<<endl;
    }
    return(0);
}
