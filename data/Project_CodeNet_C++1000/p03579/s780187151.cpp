#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;



int main(){
    int N,M; cin>>N>>M;

    vector<int> tonari[110000];

    int a,b;
    for (int i = 0; i < M; ++i) {
        cin>>a>>b; a--; b--;
        tonari[a].push_back(b);
        tonari[b].push_back(a);
    }

    vector<int> element(N,-1); //-1未確定，0偶数，1奇数

    queue<int> q;

    q.push(0);
    element[0]=0;

    bool is_nibu=true;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        int nextele=(element[node]+1)%2;
        for(auto tsugi:tonari[node]){
            if(element[tsugi]==-1){
                element[tsugi]=nextele;
                q.push(tsugi);
            }else{
                if(element[tsugi]!=nextele){
                    is_nibu=false;
                    break;
                }
            }
        }
        if(!is_nibu) break;
    }

    if(is_nibu){
        int cnt=0;
        for (int i = 0; i < N; ++i) {
            if(element[i]==0) cnt++;
        }
        cout<<(ll)cnt*(N-cnt)-M<<endl;
    }else{
        cout<<(ll)N*(N-1)/2-M<<endl;
    }


    return 0;
}