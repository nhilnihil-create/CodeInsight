#include<bits/stdc++.h>
using namespace std;

int main(){
    ostringstream oss;
    int a,b,ans=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        oss<<i;
        if((oss.str().at(0)==oss.str().at(4))&&(oss.str().at(1)==oss.str().at(3)))ans++;
        oss.str("");
        oss.clear();
    }
    cout<<ans<<endl;
    return 0;
}