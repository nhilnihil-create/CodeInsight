#include<iostream>
#include<vector>
#include<string>

const std::string MARCH = "MARCH";

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> list(6);
    for(int i = 0; i < n; i++){
        std::string input;
        std::cin >> input;
        for(int j = 0; j < MARCH.size(); j++){
            if(input[0] == MARCH[j]){
                list[j].push_back(input);
                break;
            }
        }
    }

    long long sum = 0;
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = j + 1; k < 6; k++){
                sum += list[i].size() * list[j].size() * list[k].size();
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
