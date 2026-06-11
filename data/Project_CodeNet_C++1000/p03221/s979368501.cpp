#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

string pluszero(int N){
    string T=to_string(N);
    if(T.size()>=6){
        return T;
    }
    else{
        int k=T.size();
        rep(i,6-k){
            T="0"+T;
        }
        return T;
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<ll>mark(N,0);
    //i番目の県に何個の市ができているか
    vector<string>Ans(M);
    vector<tuple<ll,ll,ll>>city(M);
    //できた年,市の番号,所属県
    rep(i,M){
        ll P,Y;
        cin>>P>>Y;
        P--;
        get<0>(city[i])=Y;
        get<1>(city[i])=i;
        get<2>(city[i])=P;
    }
    sort(city.begin(),city.end());
    rep(i,M){
        mark[get<2>(city[i])]++;
        Ans[get<1>(city[i])]=pluszero(get<2>(city[i])+1)+pluszero(mark[get<2>(city[i])]);
    }
    rep(i,M){
        cout<<Ans[i]<<endl;
    }
}