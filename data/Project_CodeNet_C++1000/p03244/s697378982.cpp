#include<iostream>
#include<vector>
#include<string>
#include<map>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> odd, even;
    int freqOdd = 0, freqEven = 0;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(i % 2 == 0){
            even[a[i]]++;
            freqEven = std::max(even[a[i]], freqEven);
        }else{
            odd[a[i]]++;
            freqOdd = std::max(odd[a[i]], freqOdd);
        }
    }

    // 偶数
    std::vector<int> evenVal, oddVal;
    for(auto m : even){
        if(m.second == freqEven){
            evenVal.push_back(m.first);
        }
    }
    // 奇数
    for(auto m : odd){
        if(m.second == freqOdd){
            oddVal.push_back(m.first);
        }
    }

    for(int i = 0; i < evenVal.size(); i++){
        for(int j = 0; j < oddVal.size(); j++){
            if(evenVal[i] != oddVal[j]){
                int evenCost = n / 2 - freqEven;
                int oddCost = n / 2 - freqOdd;
                std::cout << evenCost + oddCost << std::endl;
                return 0;
            }
        }
    }

    // これで終わらない場合 = MAXが同じ数字同士で1種
    // 全部同じ数かどうか
    if(even.size() == 1 && odd.size() == 1){
        std::cout << n / 2 << std::endl;
        return 0;
    }
    // 片方を別種にするしかない
    int nextFreqEven = 0, nextFreqOdd = 0;
    for(auto m : even){
        if(m.second >= nextFreqEven && m.second != freqEven){
            nextFreqEven = m.second;
        }
    }
    for(auto m : odd){
        if(m.second >= nextFreqOdd && m.second != freqOdd){
            nextFreqOdd = m.second;
        }
    }

    // コストの低いほうで計算
    int evenCost, oddCost;
    if(nextFreqEven >= nextFreqOdd){
        evenCost = n / 2 - nextFreqEven;
        oddCost = n / 2 - freqOdd;
    }else{
        evenCost = n / 2 - freqEven;
        oddCost = n / 2 - nextFreqOdd;
    }

    std::cout << evenCost + oddCost << std::endl;

    return 0;
}
