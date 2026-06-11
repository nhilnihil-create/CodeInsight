#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)

int main(void){
    int h,w,n,ans;cin >> h >> w >> n;
    set<int> st[w+1];//st[i]にはi列目にある障害の高さの一覧を格納
    rep(i,n){
        int h1,w1;
        cin >> h1 >> w1;
        st[w1].insert(h1);
    }//入力
    auto itr = st[0].begin();
    if(st[0].size()==0)ans=h;//1列目に障害がない
    else ans = *itr-1;//1列目の最もwが低い障害
    int loss = 0;//青木が障害にぶつかる回数
    rep1(i,w+1){//i列目のloss+iより大きい位置にある障害の中で最もwが低い障害を調べる
        while(st[i].find(i+loss)!=st[i].end())loss++;//青木が障害にぶつかる
        itr = st[i].begin();
        rep(j,(int)st[i].size()){
            if(j!=0)itr++;
            if(*itr>loss+i){
                if(ans>*itr-1)ans = *itr-1;//答えの更新
                break;//見つけたらその列の探索は終了
            }
        }
    }
    cout << ans << endl;
}