#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    vector<int> b(N);
    REP(i, N) cin >> b[i],b[i]--;
    stack<int> ans;
    for(int i=N-1;i>=0;--i) {
        bool ok=false;
        for(int j=i;j>=0;--j){
            if(b[j]==j){
                ans.push(j+1);
                b.erase(b.begin()+j);
                ok=true;
                break;
            }
        }
        if(ok) continue;
        cout<<-1<<endl;
        return 0;
    }
    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}
