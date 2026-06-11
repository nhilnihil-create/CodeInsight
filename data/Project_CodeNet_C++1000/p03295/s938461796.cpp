#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> A(M);
    vector<int> B(M);
    for(int i=0; i<M; i++) cin>>A[i]>>B[i];

    vector<pair<int,int>> p(M);
    for(int i=0; i<M; i++){
        p[i].first = B[i];
        p[i].second = A[i];
    }

    sort(p.begin(),p.end());

    int ans = 1;
    int last = p[0].first;

    for(int i=1; i<M; i++){
        if(last <= p[i].second){
            ans++;
            last = p[i].first;
        }
    }

    cout<<ans<<endl;

    return 0;
}