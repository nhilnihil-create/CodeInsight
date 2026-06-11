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
    int s;
    cin>>s;
    int L=s/100;
    int R=s%100;
    if(1<=L&&L<=12){
        if(1<=R&&R<=12) cout<<"AMBIGUOUS"<<endl;
        else cout<<"MMYY"<<endl;
    }
    else{
        if(1<=R&&R<=12) cout<<"YYMM"<<endl;
        else cout<<"NA"<<endl;
    }
}