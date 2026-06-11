#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
typedef pair<int,int> P;
using ll = long long;
const int INF=1e9;

int main(){
    string s;
    cin>>s;
    map<char,int> mp;
    rep(i,s.size()) mp[s[i]]++;
    if(s.size()<26){
        char p='a';
        while(p<='z'){
            if(mp[p]==0) break;
            else p=char(p+1);
        }
        cout<<s<<p;
        return 0;
    }
    else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout<<"-1";
            return 0;
        }
        else{
            string t=s;
            next_permutation(t.begin(),t.end());
            rep(i,26){
                if(s[i]==t[i]) cout<<s[i];
                else{
                    cout<<t[i];
                    return 0;
                }
            }
        }
    }
}