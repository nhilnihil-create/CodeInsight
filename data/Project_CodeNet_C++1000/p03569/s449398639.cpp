#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    string s;
    cin>>s;
    int ans=0;
    deque<char> que;
    rep(i, s.size()) que.push_back(s[i]);
    bool ok = true;
    while(!que.empty()){
        if(que.size()==1) break;
        else if(que.front() == que.back()){
            que.pop_front();
            que.pop_back();
        }
        else if(que.front() == 'x' && que.back() != 'x'){
            que.pop_front();
            ans++;
        }
        else if(que.front() != 'x' && que.back() == 'x'){
            que.pop_back();
            ans++;
        }
        else {
            ok=false;
            break;
        }
    }
    if(ok){
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}