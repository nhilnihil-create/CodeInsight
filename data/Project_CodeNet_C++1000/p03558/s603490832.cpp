#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

bool used[100001];
int main(){
    int k;
    cin>>k;
    deque<pint> dq;
    dq.push_back(mp(1,1));
    while(!dq.empty()){
        pint pi=dq.front();dq.pop_front();
        if(pi.first==0){
            cout<<pi.second<<endl;
            return 0;
        }
        used[pi.first]=true;
        if(!used[(pi.first+1)%k]){
            dq.push_back(mp((pi.first+1)%k,pi.second+1));
        }
        if(!used[pi.first*10%k]){
            dq.push_front(mp(pi.first*10%k,pi.second));
        }
    }
    return 0;
}