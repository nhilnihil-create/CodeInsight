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

llong LIST[3] = {3, 5, 7};
llong dfs(vector<llong> &A, llong maxv){
    llong final_ans=0;
    llong table[3] = {0, 0, 0};
    llong ans=0;
    char flg=0;
    if(A.size()==10){
        return 0;
    }
    for(int i=0; i<A.size(); i++){
        ans = ans + A[i]*pow(10, i);
        if(A[i]==7){
            table[2] = 1;
        }else if(A[i]==5){
            table[1] = 1;
        }else{
            table[0] = 1;
        }
    }
    if(ans<=maxv){
        for(int i=0; i<3; i++){
            if(table[i]==0){
                flg = 1;
                break;
            }
        }
        if(flg==0){
            final_ans++;
        }
    }
    
    for(int i=0; i<3; i++){
        A.push_back(LIST[i]);
        final_ans += dfs(A, maxv);
        A.pop_back();
    }
    return final_ans;
}

int main(){
    llong N;
    cin >> N;
    vector<llong> A;
    cout << dfs(A,N) << endl;
    return 0;
}
