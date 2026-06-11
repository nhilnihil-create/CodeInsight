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
    int N, K;
    cin >> N >> K;
    int num_kind_of_A;
    set<int> A;
    map<int, int> map_A;
    int require_num=0;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(map_A.count(a)){
            map_A[a]++;
        }
        else{
            map_A[a] = 1;
        }
        A.insert(a) ;
    }// complete set A
    int size_setA = map_A.size();
    if(size_setA <= K){
        require_num = 0;
    }
    else{
        int require_kid_num = size_setA - K;
        priority_queue<int, vector<int>, greater<int>> pq;  // 最小の要素を取り出すために pq を定義
        for(pair<int ,int> j : map_A){
            int num = j.second;
            pq.push(num);            // pq に map のAに対応する個数を挿入
        }
        for(int k=0;k<require_kid_num;k++){
            int incre ;
            incre = pq.top() ;
            require_num = require_num + incre;
            pq.pop();
        }
    }
    cout << require_num << endl;
}