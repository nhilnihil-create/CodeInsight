#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

void solve(string s) {
    vector<int> bin(3, 0);
    int len = s.size();
    for (int i = 0; i < len; i++) {
        bin[s[i] - 'a']++;
    }
    if (len >= 4 && abs(bin[0]-bin[1]) <= 1 && abs(bin[0]-bin[2]) <= 1 && abs(bin[2]-bin[1]) <= 1 ) {
        std::cout << "YES" << std::endl;
    } else if (len == 3 && bin[0] == bin[1] && bin[0] == bin[2]){
        std::cout << "YES" << std::endl;
    } else if (len == 2 && (bin[0] != 2 && bin[1] != 2 && bin[2] != 2)) {
        std::cout << "YES" << std::endl;
    } else if(len == 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    string s;

    gettimeofday(&start,NULL);

    std::cin >> s;
    solve(s);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
