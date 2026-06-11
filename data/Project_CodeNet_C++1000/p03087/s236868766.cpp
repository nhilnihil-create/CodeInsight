#include<iostream>
#include<vector>
#include<string>

int main(){
    int n, q;
    std::cin >> n >> q;
    std::string S;
    std::cin >> S;
    std::vector<int> sum(n, 0);
    for(int i = 1; i < n; i++){
        if(S[i - 1] == 'A' && S[i] == 'C'){
            sum[i] = sum[i - 1] + 1;
        }else{
            sum[i] = sum[i - 1];
        }
    }

    for(int i = 0; i < q; i++){
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        std::cout << sum[r] - sum[l] << std::endl;
    }
    return 0;
}
