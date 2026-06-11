#include<bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> red(n), blue(n);
    for(int i = 0; i < n; i++)std::cin >> red[i].first >> red[i].second;
    for(int i = 0; i < n; i++)std::cin >> blue[i].first >> blue[i].second;
    std::sort(red.begin(),red.end());
    std::sort(blue.begin(),blue.end());

    int cnt = 0;
    for(int b = 0; b < n; b++){
        auto itr = std::lower_bound(red.begin(),red.end(),std::make_pair(blue[b].first , 0));
        int max = -1;
        auto max_itr = red.end();
        for(auto i = red.begin(); i != itr; i++){
            if(i->second > max && i -> second < blue[b].second){
                max = i -> second;
                max_itr = i;
            }
        }
        if(max_itr == red.end())continue;
        red.erase(max_itr);
        cnt++;
    }
    std::cout << cnt << std::endl;
}