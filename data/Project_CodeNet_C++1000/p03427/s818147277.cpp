#include<iostream>
using namespace std;

int main(){
    string n;
    cin>>n;

    int cnt=0,l=n.length();
    for(int i=1;i<l;i++){
        if(n[i]=='9') cnt++;
    }

    int ans=0;
    if(cnt==l-1) ans=(int)(n[0]-'0')+9*(l-1);
    else ans=(int)(n[0]-'0')-1+9*(l-1);
    cout<<ans<<endl;
}