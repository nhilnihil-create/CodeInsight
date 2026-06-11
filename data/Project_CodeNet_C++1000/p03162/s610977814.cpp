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
#define INF 1000000000000
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

//selectを選択した時のn日目での最大幸福
llong dfs(llong n, llong select, vector<vector<llong> > &Table, vector<vector<llong> > &dp){
    llong maxv = -1;
    if(n==1){
        return Table[n][select];
    }
    if(dp[n][select]!=-1){
        return dp[n][select];
    }
    for(int i=0; i<3; i++){
        if(i==select){
            continue;
        }
        maxv = max(maxv, dfs(n-1, i, Table, dp)+Table[n][select]);
    }
    dp[n][select] = maxv;
    return maxv;
}

int main(){
    llong N,K;
    cin >> N;
    vector<vector<llong> > Table(N+1, vector<llong>(3, 0));
    vector<vector<llong> > dp(N+1, vector<llong>(3, -1));
    for(int i=1; i<=N; i++){
        cin >> Table[i][0] >> Table[i][1] >> Table[i][2];
    } 
    llong maxv=-1;
    for(int i=0; i<3; i++){
        maxv = max(maxv, dfs(N, i, Table, dp));
    }
    cout << maxv << endl;
}
//dp[i][j][k]
//i日においての、前日jを選択、前日kを選択した場合の通りsadf
//dp[i+1][j][k]  = dp[i][j][k]
//あとでとく
//https://atcoder.jp/contests/abc037/tasks/abc037_d
//https://atcoder.jp/contests/dp/tasks/dp_i
