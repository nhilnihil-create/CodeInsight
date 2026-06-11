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

const long long INF = 10000000000007;
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
    llong N,M;
    cin >> N >> M;
    vector<pair<llong, llong> > ANS_TABLE(M);
    vector<vector<llong> > TABLE(N);
    pair<llong, llong> X;
    map<llong, llong> dict;
    map<llong, llong> dict2;
    for(int i=0; i<M; i++){
        cin >> X.second >> X.first;
        TABLE[X.second-1].push_back(X.first);
        dict[X.first] = X.second;
        dict2[X.first] = i;
    }

    for(int i=0; i<N; i++){
        sort(TABLE[i].begin(), TABLE[i].end());
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<TABLE[i].size(); j++){
            ANS_TABLE[dict2[TABLE[i][j]]].first = dict[TABLE[i][j]];
            ANS_TABLE[dict2[TABLE[i][j]]].second = j+1;
        }
    }

    for(int i=0; i<M; i++){
        printf("%06lld%06lld\n", ANS_TABLE[i].first, ANS_TABLE[i].second);
    }
    return 0;
}
