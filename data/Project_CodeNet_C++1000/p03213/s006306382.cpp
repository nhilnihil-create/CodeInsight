#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    map<int,int> M;//num,factorial
    vector<int> S(N+1,-1);
    S.at(1) = 1;
    for(int i = 2; i <= N; i++){
        if(S.at(i)!=-1)continue;
        for(int j = 1; i*j <= N; j++){
            S.at(i*j) = i;
        }
    }
    for(int i = 2; i <= N; i++){
        int tmp = i;
        while(tmp!=1){
            M[S.at(tmp)]++;
            tmp /= S.at(tmp);
        }
    }
    set<int> F2,F4,F14,F24,F74;
    for(auto p: M){
        int num = p.first;
        int count = p.second;
        if(count<2)continue;
        else if(count<4){
            F2.insert(num);
        }else if(count<14){
            F4.insert(num);
        }else if(count<24){
            F14.insert(num);
        }else if(count<74){
            F24.insert(num);
        }else F74.insert(num);
    }

    int res = 0;
    int n74 = F74.size();
    int n24 = F24.size()+n74;
    int n14 = F14.size()+n24;
    int n4 = F4.size()+n14;
    int n2 = F2.size()+n4;
    res = n74 + n24*(n2-1) + n14*(n4-1) + n4*(n4-1)*(n2-2)/2; 
    cout<<res<<endl;
}