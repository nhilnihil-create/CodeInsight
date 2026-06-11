#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

queue<int>q[100];

int main(){
    int n,x;
    cin>>n>>x;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>a;
    rep(i,n){
        int s,t,c;
        cin>>s>>t>>c;
        s--;
        a.emplace(make_tuple(s,t,c));
    }
    int ans=0;
    rep(i,100010){
        rep(j,100){
            if(!q[j].empty()){
                if(q[j].front()==i){
                    q[j].pop();
                }
            }
        }
        rep(j,100){
            if(!a.empty()){
                if(get<0>(a.top())==i){
                    if(!q[get<2>(a.top())].empty()){
                        if(q[get<2>(a.top())].front()-1==get<0>(a.top())){
                            q[get<2>(a.top())].pop();
                            q[get<2>(a.top())].emplace(get<1>(a.top()));
                            a.pop();
                        }
                        else{
                            q[get<2>(a.top())+50].emplace(get<1>(a.top()));
                            a.pop();
                        }
                    }
                    else{
                        q[get<2>(a.top())].emplace(get<1>(a.top()));
                        a.pop();
                    }
                }
            }
        }
        int cnt=0;
        rep(j,100)if(!q[j].empty())cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}
