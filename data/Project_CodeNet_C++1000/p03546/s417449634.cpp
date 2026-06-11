#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1000000000
int h,w;
vector<vector<int>> c(10,vector<int>(10,0));
vector<vector<int>> A;

/*方針*/
//➀iから1に行くまでの消費魔力の総和のうち最小のものを探す(dfsで全探索→再帰を用いる)
//➁iが0～9まで➀を求める(一次元配列にiから1に行くためにかかる最小値を求める)
//➂h*wの二次元配列について,要素が-1でないものに対して、➁を使って総和を求める

int ans=INF;
int dfs(int a,vector<bool> &visit,int sum){//今aまで到達　visit今までに訪れた数字はtrue  sum今のところの消費魔力
    if(a==1){
        return sum;//1にたどり着いたら終わり
    }
    
    for(int i=0;i<=9;i++){
        //すでに訪れたところには行かない ex)5->9->7->5->2->1の場合5->9->7が余計であり最小値になり得ないので除く
        if(!visit[i]){
            visit[i]=true;//今訪れた
            ans=min(ans,dfs(i,visit,sum+c[a][i]));//sumにa->iにかかる魔力を加算してdfs
            visit[i]=false;//pop_back的な役割 ex)5->9->7->3で3を探索し終わったら5->9->7->4と探索したい
                           //もしvisit[3]をfalseにしないと5->9->7->4と探索しているのに3も訪れたという判定になる
        }
    }
    return ans;//1に行くまでの最小消費魔力
}

int main(){
    int i,j,k;
    cin>>h>>w;
    vector<int> change_to_one(10,0);//数字iから1へ変換するのにかかる最小コスト
    A.assign(h,vector<int>(w,0));
    for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){
            cin>>c[i][j];
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin>>A[i][j];
        }
    }

    for(i=0;i<=9;i++){//i->1への最小消費魔力を計算
        vector<bool> visit(10,false);
        ans=INF;
        visit[i]=true;
        change_to_one[i]=dfs(i,visit,0);//i->1のMIN
    }

    int answer=0;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(A[i][j]!=-1){
                answer+=change_to_one[A[i][j]];
            }
        }
    }

    cout<<answer<<endl;
    return 0;
}