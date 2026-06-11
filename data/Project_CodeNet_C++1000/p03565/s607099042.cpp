#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s,t;
    cin>>s>>t;
    int sl=s.length(),tl=t.length();
    if(sl<tl){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }
    vector<string> S;
    rep(i,sl-tl+1){
        int cnt=0;
        string ss=s;
        rep(j,tl){
            if(s[j+i]==t[j]||s[j+i]=='?'){
                cnt++;
            }
            if(cnt>0&&!(s[j+i]==t[j]||s[j+i]=='?'))cnt=0;
        }
        if(cnt==tl){
            rep(j,tl){
                ss[j+i]=t[j];
            }
            rep(j,sl){
                if(ss[j]=='?')ss[j]='a';
            }
            S.push_back(ss);
        }
    }
    if(S.empty()){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }
    sort(S.begin(),S.end());
    cout<<S.front()<<endl;
    return 0;
}