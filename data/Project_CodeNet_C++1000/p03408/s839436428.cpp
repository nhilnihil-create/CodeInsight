#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int N,M;
    cin >> N;
    map<int ,string> S;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        S[i] = s;
    }
    cin >> M;
    map<int ,string> T;
    for(int i=0;i<M;i++){
        string t;
        cin >> t;
        T[i] = t;
    }
    int score;
    int best_score;
    for(int i=0;i<N;i++){
        string choice = S[i] ;
        score=0;
        for(int j=0;j<N;j++){
            if( S[j] == choice){
                score++;
            }
        }
        for(int k=0;k<M;k++){
            if( T[k] == choice){
                score--;
            }
        }
        if(i==0){
            best_score = score;
        }
        else{
            if( best_score < score){
                best_score = score;
            }
        }
    }
    if(best_score < 0){
        best_score = 0;  // そもそも存在しない文字列を言えば0のまま
    }
    cout << best_score << endl;


}