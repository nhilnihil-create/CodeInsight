#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    char s,t; cin>>s>>t;
    int x=s-'A',y=t-'A';
    if(x<y){
        cout<<"<"<<endl;
    }else if(x>y){
        cout<<">"<<endl;
    }else{
        cout<<"="<<endl;
    }
    
}
