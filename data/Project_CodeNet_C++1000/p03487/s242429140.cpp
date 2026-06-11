#include<iostream>
#include<vector>
#include<string>
#include<map>

int main(){
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        mp[a]++;
    }

    int cnt = 0;
    for(auto m : mp){
        if(m.second >= m.first){
            cnt += m.second - m.first;
        }else{
            // 全て消す必要がある
            cnt += m.second;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
