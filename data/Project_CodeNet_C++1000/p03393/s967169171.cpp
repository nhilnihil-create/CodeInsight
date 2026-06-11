#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    string s;
    cin>>s;
    vector<int> v(26);
    rep(i, s.size()) v[s[i]-'a'] = 1;
    if(s.size()!=26) {
        rep(i, 26) if(v[i]==0) {
            s.push_back(i+'a');
            cout<<s<<endl;
            return 0;
        }
    }
    else{
        reverse(s.begin(), s.end());
        char now=s[0];
        int idx = 0;
        for(int i=1;i<=s.size()-1;i++){
            if(s[i]>now) {
                idx++;
                now=s[i];
            }
            else break;
        }
        if(idx == 25) {
            cout<<-1<<endl;
            return 0;
        }
        char mini = 'z';
        rep(i, idx+1){
            if(s[i]>s[idx+1]) mini=min(mini, s[i]);
        }
        reverse(s.begin(), s.end());
        rep(i, s.size()-idx-2) cout<<s[i];
        cout<<mini<<endl;
        return 0;
    }
}