#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    string s;cin>>s;
    int length =s.size();
    int o,x;
    rep(i,length){
        if(s[i]=='o'){
            ++o;
        }
        else {
            ++x;
        }

    }
    int v=15-length;
    if(o+v>=8)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


}
