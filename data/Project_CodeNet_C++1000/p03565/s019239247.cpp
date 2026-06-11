#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

int main(){
    string s, t;
    cin >> s >> t;
    string ans="{";
    for(int i=0; i+t.size()-1<s.size(); i++){
        string ss=s;
        bool ok=true;
        for(int j=0; j<t.size(); j++){
            if(ss[i+j] != '?' && ss[i+j] != t[j]){
                ok=false;
                break;
            }
            ss[i+j]=t[j];
        }
        if(!ok) continue;
        for(int j=0; j<s.size(); j++){
            if(ss[j] == '?') ss[j]='a';
        }
        ans=min(ans, ss);
    }
    if(ans == "{") cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;
    return 0;
}