#include <iostream>
#include <string>
#include <vector>
#include <cmath>

bool judge(std::vector<int> &h, int x, bool is_h)
{
    int sum = 0, N = h.size();
    for(int i=0; i<N; i++) sum += h[i];

    int M = 2 * sum + 1;
    // printf("M = %d\n", M);
    std::vector<std::vector<bool> > dp(N+1, std::vector<bool>(M, false));
    // for(int i=0; i<=N; i++) dp[i][sum] = true;
    dp[1][h[0]+sum] = true;
    if(!is_h) dp[1][sum-h[0]] = true;

    for(int i=2; i<=N; i++){
        for(int j=0; j<M; j++){
            // printf("i j = %d %d\n", i, j);
            if(j - h[i-1] >= 0 && dp[i-1][j-h[i-1]] == true) dp[i][j] = true;
            if(j + h[i-1] <  M && dp[i-1][j+h[i-1]] == true) dp[i][j] = true;
            // if(dp[i-1][j] == true) dp[i][j] = true;
        } 
    }
    // printf("table:\n");
    // for(int i=0; i<=N; i++){
    //     for(int j=0; j<M; j++) std::cout << dp[i][j] << " ";
    //     printf("\n");
    // }
    // printf("finish\n");
    if(x+sum < 0 || x+sum >= M) return false;
    return dp[N][x+sum];
}

int main()
{
    std::string s;
    int x, y;
    std::cin >> s >> x >> y;

    bool is_h = true;
    std::vector<int> h(1, 0), v(1, 0);
    for(auto &&itr = s.begin(); itr != s.end(); itr++){
        if(*itr == 'F'){
            if(is_h) h.back()++;
            else v.back()++;
        }
        else{
            is_h ^= 1;
            if(is_h) h.push_back(0);
            else v.push_back(0);
        }
    }

    // for(auto &&itr = h.begin(); itr != h.end(); itr++) printf("%d ", *itr);
    // printf("\n");
    // for(auto &&itr = v.begin(); itr != v.end(); itr++) printf("%d ", *itr);
    // printf("\n");

    bool b1 = judge(h, x, true);
    bool b2 = judge(v, y, false);
    if(b1 && b2) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}