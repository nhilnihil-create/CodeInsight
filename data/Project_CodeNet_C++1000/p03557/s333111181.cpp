#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<stack>
#include<map>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<utility>

using ULL = unsigned long long;
using LL = long long;
using String = std::string;
using Ints = std::vector<int>;
using Doubles = std::vector<double>;
using Bools = std::vector<bool>;
using Strings = std::vector<std::string>;
using ULLs = std::vector<ULL>;
using LLs = std::vector<LL>;

// pythonのdictionary相当
template <typename T1, typename T2>
using Dict = std::unordered_map<T1,T2>;



template <typename T>
int MegurubinarySearch(std::vector<T> &a, T key, bool mode) {
    T ng = -1;
    T ok = (int)a.size();

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;

        bool okng;
        if (mode && a[mid] >= key) okng = true;
        else if (!mode && a[mid] > key) okng = true;
        else okng = false;

        if (okng) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(void) {
    int N;
    LLs a,b,c;
    std::cin >> N;

    for(int i=0;i<N;i++){
        LL _a;
        std::cin >> _a;
        a.emplace_back(_a);
    }
    for(int i=0;i<N;i++){
        LL _b;
        std::cin >> _b;
        b.emplace_back(_b);
    }
    for(int i=0;i<N;i++){
        LL _c;
        std::cin >> _c;
        c.emplace_back(_c);
    }

    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
    std::sort(c.begin(),c.end());

    LL res = 0;

    for(auto _b:b){
        LL tmp = MegurubinarySearch<LL>(a, _b, true);
        tmp *= (N - MegurubinarySearch<LL>(c, _b, false));
        res += tmp;
    }

    std::cout << res << std::endl;

    return 0;
}