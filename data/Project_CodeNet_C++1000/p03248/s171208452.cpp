#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int N = s.size();
    bool flg = true;
    for(int i=0; i<N; ++i) {
        if(i==0 && s[i]!='1') flg = false;
        if(i==N-1 && s[i]=='1') flg = false;
        if(i!=N-1 && s[i]!=s[N-i-2]) flg = false;
    }
    if(!flg) cout << -1 << endl;
    else {
        vector<pair<int,int>> res;
        s[N-1] = '1';
        int idx = N-1;
        for(int i=N-2; i>=0; --i) {
            res.push_back(make_pair(i+1,idx+1));
            if(s[i]=='1') idx = i;
        }
        for(auto p:res) printf("%d %d\n", p.first, p.second);
    }
    return 0;
}