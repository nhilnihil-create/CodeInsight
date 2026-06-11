#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

int main(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(200001, 0);
    std::set<int> st;
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        a[tmp]++;
        st.insert(tmp);
    }

    std::sort(a.begin(), a.end());
    auto iter = std::lower_bound(a.begin(), a.end(), 1);
    int cnt = 0;
    if(st.size() < k){
        std::cout << cnt << std::endl;
        return 0;
    }
    for(int i = 0; i < st.size() - k; i++){
        cnt += *iter;
        iter++;
    }

    std::cout << cnt << std::endl;

    return 0;
}
