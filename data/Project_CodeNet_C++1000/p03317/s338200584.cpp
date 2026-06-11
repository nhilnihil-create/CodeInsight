#include<iostream>
#include<vector>
#include<string>

int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int pos1;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] == 1) pos1 = i;
    }

    int cnt = 1;
    int now = k - 1;
    if(pos1 > now){
        cnt += (pos1 - now) / (k - 1);
        now += (cnt - 1) * (k - 1);
        if(now < pos1){
            now += k - 1;
            cnt++;
        }
    }

    int tmpCnt = (n - 1 - now) / (k - 1);
    now += tmpCnt * (k - 1);
    if(now < n - 1){
        tmpCnt++;
    }

    std::cout << cnt + tmpCnt << std::endl;

    return 0;
}
