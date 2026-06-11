#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    if(n<a){
        cout<<-1<<endl;
        return 0;
    }
    int cnt=0;
    int u=n+1,l=0;
    vector<int> ans;
    while(u-l>1){
        int s=min(a-cnt,u-l-1);
        if(s<=0){
            cout<<-1<<endl;
            return 0;
        }
        for(int i=0;i<s;i++){
            ans.push_back(u-s+i);
        }
        u-=s;
        int t=min(b-1-cnt,u-l-1);
        if(cnt==0&&t!=b-1){
            cout<<-1<<endl;
            return 0;
        }
        if(u-l==1)break;
        if(t<=0){
            cout<<-1<<endl;
            return 0;
        }
        for(int i=0;i<t;i++){
            ans.push_back(l+t-i);
        }
        l+=t;
        cnt++;
    }
    for(int v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
}