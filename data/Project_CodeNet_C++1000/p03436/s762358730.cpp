#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include<queue>
#include <sstream>
#include <set>
#include<stack>
#include <utility>

const long long MOD = 1000000007;
using namespace std;
typedef long long llong;

//int isalpha(char ch): ch がアルファベットなら true を返す
//int isdigit(char ch): ch が数字なら true を返す
//int islower(char ch): ch が小文字なら true を返す
//int isupper(char ch): ch が大文字なら true を返す
//int tolower(char ch): ch の小文字を返す
//int toupper(char ch): ch の大文字を返す

//string型
//size()	文字数を返す
//Insert()	（指定した場所に）文字・文字列を挿入する
//erase()	（指定した場所の）文字・文字列を削除する
//clear()	すべての文字を削除する
//substr()	文字列の（指定した）部分文字列を返す
//replace()	（指定した）部分文字列を新しい文字列に置換する
//c_str()変換
//文字列の比較は、<=や==などを使え
//replace関数を使い、簡単に文字列を置換
//リバース関数：reverse(str.begin(), str.end());
//map<type, type> dict;で宣言
//グラフ理論用変数
//vector<vector<llong> > graph(N);

//ソート
//降順sort(v.begin(), v.end(), std::greater<Type>());

//大文字から小文字へんかん
//w[i] = w[i]-'A'+'a';

//vector
//assignメソッド　引数：サイズ、値
//与えられたサイズと値でvectorを初期化する

//queueクラス
//find()次に取り出す値の表示をする。
//pop()値を取り出す。戻り値はなし
//push()キューに値をプッシュする

//priority_queueクラス

//切り上げ
//ceil
//floor

int main(){
    llong H,W;
    cin >> H >> W;
    vector<string> Map(H);
    for(int i=0; i<H; i++){
        cin >> Map[i];
    }
    vector<vector<llong> > shortest_path(H, vector<llong>(W,-1));
    queue<pair<llong, llong> > Q;
    pair<llong, llong> D;
    D.first = 0;
    D.second = 0;
    Q.push(D);
    shortest_path[0][0] = 0;
    pair<llong, llong> NextD;
    llong d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool> > Table(H, vector<bool>(W, false));

    while(!Q.empty()){
        D = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            if(D.first+d[i][0]<0 || D.first+d[i][0]>=H || D.second+d[i][1]<0 || D.second+d[i][1]>=W){
                continue;
            }
            if(shortest_path[D.first+d[i][0]][D.second+d[i][1]]!=-1){
                continue;
            }
            if(Map[D.first+d[i][0]][D.second+d[i][1]]=='#'){
                continue;
            }
            shortest_path[D.first+d[i][0]][D.second+d[i][1]] = shortest_path[D.first][D.second] + 1;
            NextD.first = D.first+d[i][0];
            NextD.second = D.second+d[i][1];
            Q.push(NextD);
        }
    }
    if(shortest_path[H-1][W-1]==-1){
        cout << -1 << endl;
        exit(0);
    }
    llong n = shortest_path[H-1][W-1];
    llong y=H-1;
    llong x=W-1;
    llong ans=0;
    
    while(n>=0){
        Table[y][x] = true;
        n = n - 1;
        if(n==-1){
            break;
        }
        for(int i=0; i<4; i++){
            if(y+d[i][0]<0 || y+d[i][0]>=H || x+d[i][1]<0 || x+d[i][1]>=W){
                continue;
            }
            if(shortest_path[y+d[i][0]][x+d[i][1]]==n){
                y = y+d[i][0];
                x = x+d[i][1];
                break;
            }
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){

            if(Table[i][j]){
                continue;
            }
            if(Map[i][j]=='#'){
                continue;
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
