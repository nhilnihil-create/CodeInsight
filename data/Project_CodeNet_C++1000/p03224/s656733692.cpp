#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(void){
    int N;
    cin>>N;
    vector<int> s[1010];
    int sum = 0;
    int h;
    for (int i = 0; i < 1010; i++) {
        /* code */
        sum += i;
        h = i;
        if(sum > N){
            std::cout << "No" << std::endl;
            return 0;
        }
        if(sum ==N)break;
    }
    int now = 1;
    int w = 2 * N / h;
    for (int i = 0;; i++) {
        for (int j = i+1; j < w; j++) {
            s[i].push_back(now);
            s[j].push_back(now);
            now++;
            if(now == N+1)goto LOOP;
        }
    }
    LOOP:
    std::cout << "Yes" << std::endl;
    std::cout << w << std::endl;
    for (int i = 0; i < w; i++) {
        cout<<h<<" ";
        for (int j = 0; j < h; j++) {
            cout<<s[i][j]<<" ";
        }
        std::cout << "" << std::endl;
    }
    
    return 0;    
}
