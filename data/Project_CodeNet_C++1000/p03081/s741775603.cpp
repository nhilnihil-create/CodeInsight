#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int n,q;
string s;
char t[200010],d[200010];

bool isLOK(int x){
    int cur=x;
    for(int i=0;i<q;i++){
        if(s[cur]==t[i]){
            if(d[i]=='L')cur--;
            else cur++;
            if(cur<0)return false;
            if(n<=cur)return true;
        }
    }
    return true;
}

bool isROK(int x){
    int cur=x;
    for(int i=0;i<q;i++){
        if(s[cur]==t[i]){
            if(d[i]=='L')cur--;
            else cur++;
            if(cur<0)return true;
            if(n<=cur)return false;
        }
    }
    return true;
}

int main(){
    cin>>n>>q>>s;
    for(int i=0;i<q;i++){
        cin>>t[i]>>d[i];
    }
    int lng=-1,lok=n;
    while(abs(lng-lok)>1){
        int mid=(lng+lok)/2;
        if(isLOK(mid))lok=mid;
        else lng=mid;
    }
    int rok=-1,rng=n;
    while(abs(rok-rng)>1){
        int mid=(rok+rng)/2;
        if(isROK(mid))rok=mid;
        else rng=mid;
    }
    cout<<max(0,rok-lok+1)<<endl;
}
