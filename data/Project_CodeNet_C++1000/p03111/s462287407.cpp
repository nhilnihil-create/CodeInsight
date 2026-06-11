#include<iostream>
#include<vector>
#include<string>

const int INF = 1000000000;
int n;
int target[3];
std::vector<int> l;

// ref : https://img.atcoder.jp/abc119/editorial.pdf
// ref : https://drken1215.hatenablog.com/entry/2019/02/24/224100
/*
延長、縮小は合成の前後どっちでやろうが同じ
-> 合成魔法を一切これ以降使用しない場合に限り延長、縮小魔法を使用としても一般性は失われない
目的を達成するに当たって竹はA, B, Cの材料or一切使わないの4通り
-> N本あるので4^N通り
そこで合成するペアだけ全探索すればあとは目標の長さを得るためのコストを計算すればok
*/

int solve(int i = 0, int a = 0, int b = 0, int c = 0){
    if(i == n){
        // どれも目標の長さを作るのに使っていない場合はダメ
        if(!a || !b || !c) return INF;
        else return std::abs(a - target[0]) + std::abs(b - target[1]) + std::abs(c - target[2]);
    }

    int cost = INF;
    cost = std::min(cost, solve(i + 1, a, b, c)); // この竹を使わない
    // 以降使う, このとき最初の1本目は合成できていないので+10しないことに注意
    cost = std::min(cost, solve(i + 1, a + l[i], b, c) + (a ? 10 : 0));
    cost = std::min(cost, solve(i + 1, a, b + l[i], c) + (b ? 10 : 0));
    cost = std::min(cost, solve(i + 1, a, b, c + l[i]) + (c ? 10 : 0));
    return cost;
}

int main(){
    std::cin >> n;
    l.assign(n, 0);
    for(int i = 0; i < 3; i++) std::cin >> target[i];
    for(int i = 0; i < n; i++){
        std::cin >> l[i];
    }

    std::cout << solve() << std::endl;

    return 0;
}
