#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    string s;
    int N,tx,ty;
    cin >> s;
    cin >> tx >> ty;
    N = s.size();
    int nowx = 0,nowy = 0;
    // T が来たら xとyを入れ替えて
    int p = N;
    rep(i,N){
        if(s[i]=='F' && i < N)nowx++;
        else {
            p = i + 1; // s[i + 1]  から y軸に振っていく感じ
            break;
        }
    }
    vector<int> x,y;
    int now = 1; // now = 1 のとき y 方向に進む　now = 0 のとき x 方向に進む
    for(int i=p;i<N;i++){
        int cnt = 0;
        while(s[i]== 'F' && i<N){
            i++;
            cnt++;
        }
        if(now==1)y.push_back(cnt);
        else x.push_back(cnt);
        now = (now+1)%2;
    }
    vector<vector<bool>> xcan(x.size()+1,vector<bool>(16002));
    // xcan[i][j] := xをi番目まで見たときにjに行けたら 1
    // 今回はマイナスの座標も扱うので開始地点を8000にする
    // 
    xcan[0][8000+nowx] = 1;
    for(int i=0;i<x.size();i++){
        for(int j=0;j<16002;j++){
            if(xcan[i][j]){
                xcan[i+1][j+x[i]]=1;
                xcan[i+1][j-x[i]]=1;
            }
        }
    }

    vector<vector<bool>> ycan(y.size()+1,vector<bool>(16002));
    ycan[0][8000] = 1;
    for(int i=0;i<y.size();i++){
        for(int j=0;j<16002;j++){
            if(ycan[i][j]){
                ycan[i+1][j+y[i]]=1;
                ycan[i+1][j-y[i]]=1;
            }
        }
    }
    if(xcan[x.size()][tx+8000] &&  ycan[y.size()][ty+8000] )cout << "Yes" << endl;
    else cout << "No" << endl;
}
