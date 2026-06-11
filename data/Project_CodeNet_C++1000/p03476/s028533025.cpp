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

vector<bool> Eratosthenes( const int N )
{
    vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }

    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
        }
    }
    is_prime[1] = false;
    is_prime[0] = false;
    return is_prime;
}

int main(){
    llong Q;
    llong l,r;
    cin >> Q;
    vector<pair<int, int> > Query(Q);
    vector<llong> A(100001, 0);
    vector<llong> S(100002, 0);
    vector<bool>  P;
    P = Eratosthenes(100001);

    for(int i=0; i<Q; i++){
        cin >> l >> r;
        Query[i].first = l;
        Query[i].second = r;
    }
    for(int i=0; i<A.size(); i++){
        if(P[i]){
            if((i+1)%2==0 && P[(i+1)/2]){
                A[i] = 1;
            }
        }
    }
    for(int i=0; i<S.size(); i++){
        S[i+1] = S[i] + A[i];
    }
    for(int i=0; i<Query.size(); i++){
        cout << S[Query[i].second+1]-S[Query[i].first] << endl;
    }
    return 0;
}