#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< std::string > s(N);
    for(int i=0; i<N; i++){
        std::cin >> s[i];
    }
    
    int AB_cnt = 0, lastA_cnt = 0, firstB_cnt = 0, lAfB_cnt = 0;
    for(int i=0; i<N; i++){
        if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A'){
            lAfB_cnt++;
        }else if(s[i][0] == 'B'){
            firstB_cnt++;
        }else if(s[i][s[i].size()-1] == 'A'){
            lastA_cnt++;
        }
        bool A_flag = false;
        for(int j=0; j<s[i].size(); j++){
            if(s[i][j] == 'A'){
                A_flag = true;
            }else if(A_flag && s[i][j] == 'B'){
                AB_cnt++;
                A_flag = false;
            }else{
                A_flag = false;
            }
        }
    }
    
    int ans = AB_cnt;
    if(lAfB_cnt > 0){
        ans += lAfB_cnt - 1;
        if(lastA_cnt > 0){
            ans++;
            lastA_cnt--;
        }
        if(firstB_cnt > 0){
            ans++;
            firstB_cnt--;
        }
    }
    ans += std::min(lastA_cnt, firstB_cnt);
    
    std::cout << ans << std::endl;
    
    
    return 0;
}

