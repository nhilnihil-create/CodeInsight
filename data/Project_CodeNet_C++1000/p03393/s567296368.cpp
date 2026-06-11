#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    string s;
    cin>>s;
    if(s.size()<26){
        bool used[26]={};
        REP(i,s.size()) used[s[i]-'a']=true;
        REP(i,26) if(!used[i]){
            s.push_back(char(i+'a'));
            break;
        }
        cout<<s<<endl;
        return 0;
    }
    string t=s;
    if(!next_permutation(All(t))) cout<<-1<<endl;
    else{
        int i=0;
        while(i<s.size()&&s[i]==t[i]){
            ++i;
        }
        REP(k,25-i) t.pop_back();
        cout<<t<<endl;
    }
}
