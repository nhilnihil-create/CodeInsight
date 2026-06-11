#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

constexpr int INFI = 1145141919;

int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    std::vector<int> a;
    int s;
    std::cin >> s;
    a.push_back(s);

    for(int i=0; i<1000000; i++){
        a.push_back( a.back()%2==0 ? a.back()/2 : 3*a.back()+1 );
        auto buf = std::find(a.begin(), a.end(), (int)a.back());
        size_t index = std::distance(a.begin(), buf);

        if(index!=a.size()-1){
            std::cout << a.size();
            break;
        }
    }

    return 0;
}
