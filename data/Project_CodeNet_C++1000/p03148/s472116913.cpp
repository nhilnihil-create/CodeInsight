#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>

int main()
{
    typedef std::pair<long long, int> P;

    int N, K;
    std::cin >> N >> K;
    std::vector<P> sushi(N); // (d[i], t[i])
    for(int i=0; i<N; i++) scanf(" %d %lld", &(sushi[i].second), &(sushi[i].first));

    std::sort(sushi.begin(), sushi.end(), std::greater<P>());

    long long sum = 0;
    std::priority_queue<long long,
        std::vector<long long>,
        std::greater<long long> > q; // 種類がかぶった寿司を入れる
    std::unordered_map<int, int> exist; 
    for(int i=0; i<K; i++){
        sum += sushi[i].first;
        if(exist.find(sushi[i].second) == exist.end()) exist[sushi[i].second];
        else q.push(sushi[i].first);
    }
    sum += exist.size() * exist.size();

    std::vector<long long> sum_list;
    sum_list.push_back(sum);
    for(int i=K; i<N; i++){
        if(q.empty()) break;
        if(exist.find(sushi[i].second) == exist.end()){
            exist[sushi[i].second];
            long long sub = q.top(); q.pop();
            sum_list.push_back(sum_list.back() - sub + sushi[i].first + 2*exist.size()-1);
        }
    }

    std::cout << *std::max_element(sum_list.begin(), sum_list.end()) << std::endl;
}