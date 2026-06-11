#include<bits/stdc++.h>
using namespace std;
int main(){

    int a,b,c;
    cin>>a>>b>>c;
    int res=b/a;
    if(res>=c){
        cout<<c<<endl;
    }
    else if(res<c){
        cout<<res<<endl;
    }

}