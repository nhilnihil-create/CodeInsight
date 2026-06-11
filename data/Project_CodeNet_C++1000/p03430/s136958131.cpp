#include<iostream>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
#include<memory>
using namespace std;
using ll=long long;

void cmax(int& lhs,int rhs){lhs=max(lhs,rhs);}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int half=s.size()/2;
    
    vector<vector<vector<int>>> dp(half+1,vector<vector<int>>(half+1,vector<int>(k+1)));
    for(int i=0;i<=half;i++){
        for(int j=0;j<=half;j++){
            for(int l=0;l<=k;l++){
                if(i<half){
                    cmax(dp[i+1][j][l],dp[i][j][l]);
                }
                if(j<half){
                    cmax(dp[i][j+1][l],dp[i][j][l]);
                }
                if(i<half &&j<half){
                    if(s[i]!=s[s.size()-1-j] && l<k) cmax(dp[i+1][j+1][l+1],dp[i][j][l]+1);
                    if(s[i]==s[s.size()-1-j]) cmax(dp[i+1][j+1][l],dp[i][j][l]+1);
                }
                if(l<k) cmax(dp[i][j][l+1],dp[i][j][l]);
            }
        }
    }
    

    vector<vector<int>> posL(s.size()+1,vector<int>(26,-1));
    for(int i=0;i<s.size();i++) posL[i+1]=posL[i],posL[i+1][s[i]-'a']=i;
    vector<vector<int>> posR(s.size()+1,vector<int>(26,s.size()));
    for(int i=s.size()-1;i<s.size();i--) posR[i]=posR[i+1],posR[i][s[i]-'a']=i;

    vector<vector<vector<int>>> dp2(s.size()+1,vector<vector<int>>(s.size()+1,vector<int>(k+1)));
    for(int i=0;i<s.size();i++) for(int j=0;j<=k;j++) dp2[i][i+1][j]=1;
    for(int v=2;v<=s.size();v++){
        for(int i=0;i<s.size();i++){
        int j=i+v;
        if(i+v>s.size()) continue;
            for(int l=0;l<=k;l++){
                if(l>0){
                    cmax(dp2[i][j][l],dp2[i+1][j-1][l-1]+2);
                    cmax(dp2[i][j][l],dp2[i][j][l-1]);
                }
                cmax(dp2[i][j][l],dp2[i+1][j][l]);
                cmax(dp2[i][j][l],dp2[i][j-1][l]);
                if(i+1<=posL[j][s[i]-'a']) cmax(dp2[i][j][l],dp2[i+1][posL[j][s[i]-'a']][l]+2);
                if(posR[i][s[j-1]-'a']<=j-2) cmax(dp2[i][j][l],dp2[posR[i][s[j-1]-'a']+1][j-1][l]+2);
            }
        }
    }

    int res=0;
    int tmp=s.size()%2;
    for(int i=0;i<=half;i++){
        for(int j=0;j<=half;j++){
            for(int l=0;l<=k;l++){
                cmax(res,dp[i][j][l]*2+dp2[i][half+tmp][k-l]);
                cmax(res,dp[i][j][l]*2+dp2[half][s.size()-j][k-l]);
            }
        }
    }
    cout<<dp2[0][s.size()][k]<<endl;
    
    return 0;
}
