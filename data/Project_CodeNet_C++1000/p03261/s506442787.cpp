#include <iostream>
#include <set>

int main(void){
    int N;
    char c;
    std::string ans="Yes";
    std::cin >> N;
    std::set<std::string> words;

    for (int i=0; i<N; ++i){
        std::string W;
        std::cin >> W;
        if (i == 0){
            words.insert(W);
            c = W.at(W.size() - 1);
        } else {
            if (c != W.at(0)){
                ans = "No";
                break;
            } else if (words.find(W) != words.end()){
                ans = "No";
                break;
            } else {
                words.insert(W);
                c = W.at(W.size() - 1);
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
