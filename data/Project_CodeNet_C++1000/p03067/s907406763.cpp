#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    if(a>b)
        swap(a,b);
    if(c>=a && c<=b)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
