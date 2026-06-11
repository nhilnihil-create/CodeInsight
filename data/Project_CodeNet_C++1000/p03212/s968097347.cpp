#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

ll N;

void SFT(ll num,int B,ll &count){
    if(num>N){
        return;
    }
    if(B==0b111){
        count++;
    }
    SFT(num*10+3,B|0b001,count);
    SFT(num*10+5,B|0b010,count);
    SFT(num*10+7,B|0b100,count);
}

int main(){
    cin>>N;
    ll c=0;
    SFT(0,0b000,c);
    cout<<c<<endl;  
}