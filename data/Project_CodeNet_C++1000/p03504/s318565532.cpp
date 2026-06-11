#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n,c,ans=0;
    cin>>n>>c;

    vector<vvi> rec(c+1);
    rep(i,n){
        lli s,t,c;
        cin>>s>>t>>c;
        if(rec[c].size()==0){
            vi  x={s,t};
            rec[c].push_back(x);
        }
        else{
            unsigned int si=rec[c].size();
            si--;
            if(rec[c][si][1]==s){
                rec[c][si][1]=t;
            }
            else{
                vi x={s,t};
                rec[c].push_back(x);
            }
        }
    }
        vi ttc(2200000,0);
    rep(j,c+1){
            vi tt(2200000,0);
            rep(k,rec[j].size()){
                tt[rec[j][k][0]*2-1]+=1;
                tt[rec[j][k][1]*2]-=1;
            }
        for(int i=1;i<2200000;i++){
        tt[i]+=tt[i-1];
    }
    rep(k,2200000){
        if(tt[k]>0)ttc[k]++;
    }
    rep(i,2200000){
        ans=max(ans,ttc[i]);
    }

    }

    out(ans);
}