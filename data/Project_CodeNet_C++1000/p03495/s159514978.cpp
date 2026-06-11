#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int n,k;
    cin>>n>>k;
    map<int,int> A;

    rep(i,n){
        int a;
        cin>>a;
        A[a]++;
    }

    priority_queue<int, vector<int>, greater<int> > que;//小さい順priority_queue記憶しておく
    for(auto p:A){
        que.push(p.second);
    }

    int ans=0;
    rep(i,A.size()-k){
        ans+=que.top();
        que.pop();
    }

    cout<<ans<<endl;
}

//mapをvalueでソートするには？