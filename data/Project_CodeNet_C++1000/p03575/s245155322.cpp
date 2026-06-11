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
//insert()	（指定した場所に）文字・文字列を挿入する
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

void dfs(llong node, vector<vector<llong> > &graph, vector<bool> &seen, llong a, llong b){
    llong next_node;

    if(seen[node]){
        return;
    }
    seen[node] = true;
    for(int i=0; i<graph[node].size(); i++){
        next_node = graph[node][i];
        if(a==node && b==next_node){
            continue;
        }
        if(a==next_node && b==node){
            continue;
        }
        dfs(next_node, graph, seen, a, b);
    }
}

int main(){
    llong N,M;
    llong a,b;
    llong ans=0;
    cin >> N >> M;
    vector<vector<llong> > graph(N);
    vector<vector<llong> > graph_copy(N);
    vector<vector<llong> > edge(M);
    vector<bool> seen(N);
    char flg;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        edge[i].push_back(a-1);
        edge[i].push_back(b-1);
    }
    for(int i=0; i<edge.size(); i++){
        seen.assign(N, false);
        flg = 0;
        dfs(0, graph, seen, edge[i][0], edge[i][1]);
        for(int j=0; j<seen.size(); j++){
            if(seen[j]==false){
                flg = 1;
            }
        }
        if(flg==1){
            ans++;
        }
    }
    cout << ans << endl;
}