#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> c(n - 1), s(n - 1), f(n - 1);
    for(int i = 0; i < n - 1; i++){
        std::cin >> c[i] >> s[i] >> f[i];
    }

    for(int i = 0; i < n - 1; i++){
        int time = s[i];
        time += c[i];

        // 今i + 1地点に来た
        for(int now = i + 1; now < n - 1; now++){
            // 待ち時間の考慮
            if(time < s[now]){
                time = s[now];
            }else{
                if(time % f[now] != 0){
                    time += f[now] - time % f[now];
                }
            }

            // 乗る
            time += c[now];
        }

        std::cout << time << std::endl;
    }
    std::cout << 0 << std::endl;
    return 0;
}
