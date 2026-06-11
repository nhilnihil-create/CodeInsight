#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define all(v) (v).begin(),v.end()
#define fi first
#define se second
const ll inf=(1e18);
const ll mod=1000000007;
vector<string> dp(10010);
int main(){
vector<int> match={0,2,5,5,4,5,6,3,7,6};
int n,m;
cin>>n>>m;
vector<char> hav(m);
for(int i=0;i<m;i++)cin>>hav[i];
sort(all(hav),greater<char>());
for(int i=0;i<m;i++){
    for(int j=n;j>=0;j--){
        if(j-match[(int)(hav[i]-'0')]>=0){
            if(j!=n&&dp[j].size()==0)continue;
            string tmp=dp[j];
            tmp.push_back(hav[i]);
           if(tmp.size()>dp[j-(int)(match[hav[i]-'0'])].size())dp[j-match[hav[i]-'0']]=tmp;
            else if(tmp.size()==dp[j-(int)(match[hav[i]-'0'])].size()){
                int k=tmp.size();
                while(--k>=0){
                      if(tmp[k]>dp[j-match[hav[i]-'0']][k]){dp[j-match[hav[i]-'0']]=tmp;break;}
                }
            }
        }
    }
}
sort(all(dp[0]),greater<char>());
cout<<dp[0]<<endl;
}


