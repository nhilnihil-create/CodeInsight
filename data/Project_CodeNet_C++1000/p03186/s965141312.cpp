#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,ans=0;
    cin>>a>>b>>c;

    if(b>=c||a+b>=c){
        cout<<b+c<<endl;
        return 0;
    }

    ans+=a+(b*2);

    if(c-b-a!=0) ans++;

    cout<<ans<<endl;
}
