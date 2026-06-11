#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
int gcd(int a,int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b/a>=c){
        cout<<c<<endl;
        return 0;
    }
    else 
    cout<<b/a<<endl;
}