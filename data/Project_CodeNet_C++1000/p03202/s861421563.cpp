#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define brep(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<n;i++)
#define brep1(i,n) for(int i=n-1;i>=1;i--)

vector<int> a;

bool check(int x){//x文字以内で要件を満たせるかどうか
    map<int,int>mp;//(mp[x]-1)はx文字目で何種類文字を使っているかを表す
    rep1(i,a.size()){
        if(a[i-1]<a[i])continue;//後ろに文字追加してるだけなのでスキップ
        if(x==1)return false;//これがないと繰り上がり部分でTLE
        mp[a[i]]++;//a[i]文字目の番号を+1
        mp.erase(mp.upper_bound(a[i]),mp.end());//a[i]より後ろはリセット
        brep1(j,a[i]+1){//繰り上がり処理
            if(mp[j]>=x){
                if(j==1) return false;//最初の文字を越えて繰り上がるようなら失敗
                mp[j]=0;mp[j-1]++;//繰り上がり
            }
            else break;//繰り上がり処理の終了
        }
    }
    return true;//最後までいったら成功
}

int main(void){
    int n;cin >> n;
    rep(i,n){int num;cin >>num;a.emplace_back(num);}//入力
    int min=0;int max=n;
    while(max-min>1){//min<x<=maxでxを二部探索,x=maxになり次第探索を終了
        int mid = (max+min)/2;
        if(check(mid))max=mid;
        else min = mid;
    }
    cout << max << endl;
}