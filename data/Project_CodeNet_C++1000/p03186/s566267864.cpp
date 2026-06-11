#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int ans;
    if(a+b+1>=c){
        ans=b+c;
    }
    else{
        ans=a+b+1+b;
    }
    cout<<ans;
}
