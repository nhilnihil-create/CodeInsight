#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define rep(_i,init,N) for(int _i=init;_i<N;++_i)
#define REP(_i,N) for(int _i=0;_i<N;++_i)
#define REP2(_i,_len,N) for(int _i=0,_len=(N);_i<_len;++_i)
#define VREP(v,_itr,_end) for(auto _itr=(v).begin(),_end=(v).end();_itr!=_end;++_itr)
#define VCREP(v,_itr,_end) for(auto _itr=(v).cbegin(),_end=(v).cend();_itr!=_end;++_itr)

using namespace std;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb > vvb;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll > vvll;

#define SIZE 1000
#define MOD 1'000'000'009

int main(int argc, const char * argv[]) {
    string s,t;
    cin>>s>>t;
    
    int lenS=(int)s.length(),lenT=(int)t.length();
    
    vvi dp(lenS+1);
    REP(i,lenS+1){
        dp[i].resize(lenT+1,0);
    }
    REP(i,lenS) REP(j,lenT){
        if(s[i]==t[j]){
            dp[i+1][j+1]=dp[i][j]+1;
        }else{
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    
    int len=dp[lenS][lenT];
//    vc ansV(len,0);
    string ans;
    ans.resize(len, 0);
    int i=lenS,j=lenT;
    
    while(len>0){
        if(s[i-1]==t[j-1]){
            ans[len-1]=s[i-1];
            --i;
            --j;
            --len;
        }else if(dp[i][j]==dp[i-1][j]){
            --i;
        }else{
            --j;
        }
    }
    cout<<ans<<endl;
    return 0;
}