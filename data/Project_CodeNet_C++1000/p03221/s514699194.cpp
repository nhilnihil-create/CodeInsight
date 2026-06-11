#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <ios>
#include <iomanip>
int main() {
    int N,M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> City(N+1,std::vector<int>(0,0));
    std::vector<std::pair<int,int>> Input(M+1);
    for(int i=1;i<M+1;i++){
        int P_in,C_in;
        std::cin >> P_in >> C_in;
        City[P_in].push_back(C_in);
        Input[i].first = P_in;
        Input[i].second = C_in;
    }
    // 各県ごとに市を整列
    for(int i=1;i<N+1;i++){
        std::sort(City[i].begin(),City[i].end());
    }

    for(int i=1;i<M+1;i++){
        std::cout << std::setfill('0') << std::right << std::setw(6) << Input[i].first;
        int CityNum;
        CityNum = std::lower_bound(City[Input[i].first].begin(),City[Input[i].first].end(),Input[i].second) - City[Input[i].first].begin() + 1;
        std::cout << std::setfill('0') << std::right << std::setw(6) << CityNum << std::endl;
    }
    return 0;
}