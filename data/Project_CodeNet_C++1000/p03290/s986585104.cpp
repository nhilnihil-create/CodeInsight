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
    int D, G;cin>>D>>G;
    vec_int p(D), c(D);
    rep(i,D)cin>>p.at(i)>>c.at(i);

    int min_problem = INT_MAX;
    for(int pattern=0;pattern<pow(2,D);pattern++){
        int temp_score = 0;
        int num = 0;
        for(int i=0;i<D;i++){
            if((pattern/((int)pow(2,i)))%2==1){
                temp_score += 100*(i+1)*p.at(i) + c.at(i);
                num += p.at(i);
            }
        }

        while(temp_score<G){
            for(int i=D-1;i>=0;i--){
                if((pattern/((int)pow(2,i)))%2==1)continue; //ここはもう足したからパス
                //Gを超えられるかチェック
                if(temp_score+(100*(i+1))*(p.at(i)-1)>=G){
                    num+= ((G-temp_score)/(100*(i+1))+1);
                    if((G-temp_score)%(100*(i+1))==0)num=num-1;
                    temp_score = temp_score + ((G-temp_score)/(100*(i+1))+1)*(100*(i+1));
                    if((G-temp_score)%(100*(i+1))==0)temp_score = temp_score-100*(i+1);
                    break;
                }else{
                    num+= p.at(i)-1;
                    temp_score = temp_score + (100*(i+1))*(p.at(i)-1);
                }
            }
            break;
        }
        if(G<=temp_score){
        if(num<min_problem){
            min_problem = num;
        }
        }
    }

cout<<min_problem<<endl;


    return 0;
}