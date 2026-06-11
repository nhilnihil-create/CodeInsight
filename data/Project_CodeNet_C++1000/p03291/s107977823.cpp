#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define Mod 1000000007

int main() {
    string s;
    cin>>s;
    ll count[3]={0,0,0},nowh=1;
    for (int i = 0; i < s.length(); ++i) {
        string now=s.substr(i,1);
        if(now=="A"){
            count[0]+=nowh;
        }
        if(now=="B"){
            count[1]+=count[0];
        }
        if(now=="C"){
            count[2]+=count[1];
        }
        if(now=="?") {
            count[2]=count[2]*3+count[1];
            count[1]=count[1]*3+count[0];
            count[0]=count[0]*3+nowh;
            nowh*=3;
        }
        count[0]%=Mod;
        count[1]%=Mod;
        count[2]%=Mod;
        nowh%=Mod;
        //cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<" "<<nowh<<endl;
    }
    cout<<count[2];
    return 0;
}
