#include <iostream>
#include <vector>
#include <string>

int main(){
    int N;
    std::cin >> N;
    std::vector<double> x(N);
    std::vector<std::string> u(N);
    for(auto i = 0; i < N; i++){
        std::cin >> x.at(i) >> u.at(i);
    }

    double ans = 0;
    for(auto i = 0; i < N; i++){
        if(u.at(i) == "JPY"){
            ans += x.at(i);
        }
        else{
            ans += (x.at(i) * 380000);
        }
    }

    printf("%.6lf\n", ans);

    return 0;
}
