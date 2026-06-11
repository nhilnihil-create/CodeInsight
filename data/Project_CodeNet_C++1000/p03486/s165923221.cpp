#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    string s, t;
    cin>>s>>t;
    vector<char> chara, chara2;
    rep(i, s.size()) chara.push_back(s[i]);
    sort(all(chara));
    rep(i, s.size()) s[i]=chara[i];
    rep(i, t.size()) chara2.push_back(t[i]);
    sort(all(chara2));
    rep(i, t.size()) t[t.size()-1-i]=chara2[i];
    //cout<<s<<sp<<t<<endl;
    bool same=true, ok=true;
    rep(i, min(s.size(), t.size())){
        if(s[i]!=t[i]) same=false;
        if(!same && s[i]>t[i]) ok=false;
        if(!same && ok) break;
    }
    if(same){
        if(s.size()<t.size()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else{
        cout<<(ok ? "Yes": "No")<<endl;
    }
    return 0;
}
