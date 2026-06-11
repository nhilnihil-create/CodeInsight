#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    vector<string> s(N);
    int l=0,r=N;
    cout<<l<<endl;
    cin>>s[l];
    if(s[l]=="Vacant") return 0;
    REP(_,20){
        int mid=(l+r)>>1;
        cout<<mid<<endl;
        cin>>s[mid];
        if(s[mid]=="Vacant") break;
        if((s[mid]==s[l])==((mid-l+1)&1)) l=mid;
        else r=mid;
    }
}
