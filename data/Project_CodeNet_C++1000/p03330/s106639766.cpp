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
    int N, C; cin>>N>>C;
    vector<vector<int>> D(C, vector<int>(C));
    vector<vector<int>> c(N, vector<int>(N));
    rep(i,C){
        rep(j,C){
            cin>>D.at(i).at(j);
        }
    }
    rep(i,N){
        rep(j,N){
            cin>>c.at(i).at(j);
        }
    }

    vec_int iwakan0(C,0); // (X+Y)%3=0のマスを色iにしたときの違和感の合計
    vec_int iwakan1(C,0);
    vec_int iwakan2(C,0);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<C;k++){
                int color = c.at(i).at(j)-1;
                if((i+j)%3==0){
                    iwakan0.at(k) += D.at(color).at(k);
                }else if((i+j)%3==1){
                    iwakan1.at(k) += D.at(color).at(k);
                }else{
                    iwakan2.at(k) += D.at(color).at(k);
                }
            }
        }
    }
    /*
    int min0 = INT_MAX;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    rep(i,C){
        if(min0>iwakan0.at(i)){
            min0=iwakan0.at(i);
        }
        if(min1>iwakan1.at(i)){
            min1=iwakan1.at(i);
        }
        if(min2>iwakan2.at(i)){
            min2=iwakan2.at(i);
        }
    }
    cout<<min0+min1+min2<<endl;
    */
   int min = INT_MAX;
   for(int i=0;i<C;i++){
   for(int j=0;j<C;j++){
       if(i==j)continue;
   for(int k=0;k<C;k++){
       if(i==k || j==k)continue;
       int temp = iwakan0.at(i)+iwakan1.at(j)+iwakan2.at(k);
       if(min>temp)min=temp;

   }
   }
   }
   cout<<min<<endl;

    return 0;
}