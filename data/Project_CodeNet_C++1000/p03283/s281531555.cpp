#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N, M, Q; cin>>N>>M>>Q;
    vec_int L(M), R(M);
    vec_int p(Q), q(Q);
    rep(i,M)cin>>L.at(i)>>R.at(i);
    rep(i,Q)cin>>p.at(i)>>q.at(i);


    vector<vector<int>> train_ss(N+1, vector<int>(N+1,0));
    rep(i,M){
        train_ss.at(L.at(i)).at(R.at(i))++;
    }

    vector<vector<int>> honsuu(N+1, vector<int>(N+1,0)); // honsuu.at(i).at(j): iからjまでの区間に含まれている電車の本数
    for(int i=1;i<N+1;i++){
        for(int j=i;j<N+1;j++){
            if(i==j){
                honsuu.at(i).at(j) = train_ss.at(i).at(j);
            }else{
                int temp = 0;
                for(int k=i;k<=j;k++){
                    temp+=train_ss.at(k).at(j);
                }
                honsuu.at(i).at(j) = honsuu.at(i).at(j-1) + temp;
            }
        }
    }

    rep(i,Q){
        cout<<honsuu.at(p.at(i)).at(q.at(i))<<endl;
    }


    return 0;
}