#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    string s,t="KIHBR",tmp;
    cin>>s;
    int ins[]={0,3,4,5};
    for(int bit=0;bit<16;++bit){
        tmp=t;
        for(int i=3;i>=0;--i){
            if(bit>>i&1) t.insert(t.begin()+ins[i],'A');
        }
        if(s==t){
            cout<<"YES"<<endl;
            return 0;
        }
        t=tmp;
    }
    cout<<"NO"<<endl;
}
