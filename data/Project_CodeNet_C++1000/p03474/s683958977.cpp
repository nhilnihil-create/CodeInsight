#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, M;
    cin >> N >> M;
    string s; cin>>s;
    ll flg=0;
    rep(i,0,s.size()){
        if(s[N]=='-'){
            rep(j,0,10){
                if(i!=N&&s[i]-'0'==j){
                    flg+=1;
                }
            }
        }
    }
    cout <<(flg==N+M ? "Yes":"No")<< endl;
    return 0;
}