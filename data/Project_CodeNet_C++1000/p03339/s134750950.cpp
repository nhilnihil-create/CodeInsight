#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int n;
    std::string S;
    std::cin >> n >> S;
    std::vector<int> a(n, 0);
    std::vector<int> sum(n, 0);
    if(S[0] == 'W'){
        a[0] = 1;
        sum[0] = 1;
    }
    for(int i = 1; i < n; i++){
        if(S[i] == 'W') a[i] = 1;
        sum[i] += sum[i - 1] + a[i];
    }


    int minNum = n;
    minNum = std::min(minNum, (n - 1) - (sum[n - 1] - sum[0])); // 左端をリーダとする
    minNum = std::min(minNum, sum[n - 2]); // 右端をリーダとする
    for(int i = 1; i < n - 1; i++){
        int turnLeft = (n - 1 - i) - (sum[n - 1] - sum[i]);
        int turnRight = sum[i - 1];
        minNum = std::min(minNum, turnLeft + turnRight);
    }

    std::cout << minNum << std::endl;
    return 0;
}
