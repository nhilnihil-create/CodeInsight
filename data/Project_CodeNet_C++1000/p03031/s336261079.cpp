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
    int N, M; cin>>N>>M;
    vec_int k(M);
    vector<vector<int>> s(M);
    rep(i,M){
        cin>>k.at(i);
        vec_int temp(k.at(i));
        rep(j,k.at(i))cin>>temp.at(j);
        s.at(i) = temp;
    }
    vec_int p(M);
    rep(i,M){
        cin>>p.at(i);
    }

    int tott = 0;
    for(int combi=0;combi<pow(2,N);combi++){
        bitset<10> bits(combi);
        int num=0;
        for(int i=0;i<M;i++){
            // 電球:iに関して
            vec_int light_arr = s.at(i);
            int tot_on = 0;
            for(int j=1;j<N+1;j++){//N個のスイッチがlight_arrの中にあるかをチェック
            if(bits[j-1]==0)continue;
                for(auto aaa : light_arr){
                    if(aaa==j){
                        tot_on++;
                        break;
                    }
                }
            }
            if(tot_on%2==p.at(i)){
                num++;
            }
        }
        if(num==M){
            tott++;
        }
    }
    cout<<tott<<endl;



    return 0;
}