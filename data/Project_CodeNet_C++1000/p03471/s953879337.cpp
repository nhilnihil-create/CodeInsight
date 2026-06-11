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
    int N,Y;
    cin>>N>>Y;
    for(int x=0;N>=x;++x){
        for(int y=0;N>=y;++y){
            if(10000*x+5000*y+1000*(N-x-y)==Y&&N-x-y>=0){
                cout<<x<<" "<<y<<" "<<N-x-y<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;
}
