#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
int main(void){
    int n;
    std::cin >> n;
    std::map<std::string, std::vector<std::pair<int, int>>> a;
    std::string s;
    int p;
    for(int i = 0; i < n; i++){
        std::cin >> s >> p;
        // if(a.find(s) == a.end()) a[s].resize(0);
        a[s].push_back(std::make_pair(p, i));
    }
    for(auto i = a.begin(); i != a.end(); i++){
        std::vector<std::pair<int, int>> tmp = i->second;
        std::sort(tmp.rbegin(), tmp.rend());
        for(int i = 0; i < tmp.size(); i++){
            std::cout << tmp[i].second + 1 << std::endl;
        }
    }
    return 0;
}