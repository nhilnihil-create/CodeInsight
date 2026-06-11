#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    int A[2020];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    int ans=INT_MAX;
    for(int i=0; i<N; i++){
        //A[i]未満のリストを作る
        vector<int> list(0);
        list.push_back(-1);
        for(int j=0; j<N; j++){
            if(A[j]<A[i]) list.push_back(j);
        }
        list.push_back(N);

        vector<int> glo(0);
        //
        for(int j=0; j<list.size()-1; j++){
            vector<int> now(0);
            for(int k=list.at(j)+1; k<list.at(j+1); k++){
                now.push_back(A[k]);
            }
            if(now.size() < K) continue;
            sort(now.begin(),now.end());
            for(int k=0; k<now.size()-K+1; k++){
                glo.push_back(now.at(k));
            }
        }

        //
        sort(glo.begin(),glo.end());
        if(glo.size()<Q) continue;
        ans=min(ans,glo.at(Q-1)-glo.at(0));
    }
    cout << ans << endl;
}