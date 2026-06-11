#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
 
pair<int,int>p;

bool kaibun(string S){
    if(S.size()==1)return true;
  	for(int i=0;i<=S.size()/2;i++){
        if(S[i]!=S[S.size()-1-i])return false;
    }
    return true;
}

signed main(){
    string S;cin>>S;
    string Z="";
    bool ok=true;
    REP(i,S.size()){
        if(S[i]!='x')Z+=S[i];
    }
    ok=kaibun(Z);
    if(ok){
        int b=0;
        int count=0;
        vector<int>vec(Z.size()+1,0);
        for(int i=0;i<=S.size();i++){
            if(S[i]=='x')b++;
            else{
                vec[count]=b;
                b=0;
                count++;
            }
          	if(i==S.size()&&b!=0){
				vec[count]=b;
            }
        }
        int ans=0;
        for(int i=0;i<(Z.size()+1)/2;i++){
            ans+=abs(vec[i]-vec[Z.size()-i]);
        }
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;
}