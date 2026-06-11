#include<bits/stdc++.h>
using ll = long long;
const ll INF_LL = 1000000000000;
#define fir first
#define sec second

int main()
{
    int n,c;
    std::cin >> n >> c;
    std::vector<std::vector<bool>> ch(c,std::vector<bool>(100010));
    for(int i = 0; i < n; i++){
        int s,t,c;
        std::cin >> s >> t >> c;
        c--;
        for(int i = s; i <= t; i++){
            ch[c][i] = true;
        }
    }
    std::vector<std::pair<int,int>> kukan;
    for(int i = 0; i < c; i++){
        for(int j = 1; j < 100005;){
            if(ch[i][j]){
                int k = j;
                while(ch[i][j])j++;
                kukan.push_back({j,k});
            }else{
                j++;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 100005; i++){
        int cur = 0;
        for(int j = 0; j < c; j++){
            if(ch[j][i])cur++;
        }
        cnt = std::max(cnt,cur);
    }
    std::cout << cnt << std::endl;


    /*
    //区間スケジューリング
    int cnt = 0;
    int cur = -1;
    std::sort(kukan.begin(), kukan.end());
    for(int i = 0; i < n; i++){
        if(kukan[i].second >= cur){
            cnt++;
            cur = kukan[i].first;
        }
    }
    std::cout << cnt << std::endl;
    */
}
