#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
 
int main(){
    string S;
    cin>>S;
    if(*S.begin()=='A'){
        
        ll cnt=0;
        ll id=0;
        rep(i,2,S.size()-1){
            if(S[i]=='C'){
                cnt++;
                if(cnt==1)id=i;
            }
        }
        
        ll flg=1;
        rep(i,0,S.size()){
            if(i==0||i==id)continue;
            
            if (islower(S[i]))flg*=1;
            else flg*=0;

        }

        if(cnt==1&&flg==1){cout<<"AC"<<endl;return 0;}
    }
    cout<<"WA"<<endl;
    return 0;
}