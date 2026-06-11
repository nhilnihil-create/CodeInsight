//
// Created by TakahiroYamaji on 2020/07/29.
//
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int, int>P;
int N, M;
P p[100000];
bool comp(P& x, P& y){
    return x.second < y.second;
}

int main(){
    std::cin >> N >> M;
    for (int i=0;i<M;i++){
        std::cin >> p[i].first >> p[i].second;
    }
    std::sort(p, p+M, comp);
    int res = 1;
    int end = p[0].second;
    for (int i=1;i<M;i++){
        if (end > p[i].first) continue;
        else{
            res++;
            end = p[i].second;
        }
    }
    std::cout << res << std::endl;
    return 0;
}
