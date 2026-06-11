#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
    string s,key="keyence";
    cin>>s;
    auto solve=[&](int l){
        int r=0;
        while(l+r<s.size()){
            string t=s;
            t.erase(l,r);
            if(t==key){
                cout<<"YES"<<endl;
                return true;
            }
            r++;
        }
        return false;
    };
    rep(i,s.size()){
        if(solve(i)){
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}