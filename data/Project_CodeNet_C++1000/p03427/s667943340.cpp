#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    string n;
    cin>>n;

    int s=n.size();
    string str="";

    rep(i,s) str+='9';

    int res=0;
    for(char c='0';c<='9';c++){
        str[0]=c;
        if(str<=n){
            int num=0;
            for(int j=0;j<str.size();j++){
                num+=(int)(str[j] - '0');
            }
            if(res<num) res=num;
        }
    }
    cout<<res<<endl;
    return 0;
}