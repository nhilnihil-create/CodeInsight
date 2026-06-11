#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#define INF 100000000000000
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

int main(){
    llong N,Q;
    string str;
    cin >> N >> Q;
    cin >> str;
    vector<pair<llong, llong> > Query(Q);
    llong l,r;
    for(int i=0; i<Query.size(); i++){
        cin >> l >> r;
        Query[i].first =l;
        Query[i].second =r;
    }
    vector<llong> A(N, 0);
    vector<llong> S(N+1, 0);
    for(int i=0; i<str.size()-1; i++){
        if(str[i]=='A' && str[i+1]=='C'){
            A[i+1] = 1;
        }
    }
    for(int i=0; i<A.size(); i++){
        S[i+1] = S[i] + A[i];
    }
    for(int i=0; i<Query.size(); i++){
        cout << S[Query[i].second]-S[Query[i].first] << endl;
    }
    return 0;
}

//00:81 s