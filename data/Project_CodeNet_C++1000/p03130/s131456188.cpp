#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> counter(vector<int> nums){
    map<int, int> outcome;
    for (auto n: nums){
        outcome[n]++;
    }
    return outcome;
}

int main(){
    vector<int> nums;
    for (int i=0;i<3;i++){
        int a, b;cin>>a>>b;
        nums.push_back(a);
        nums.push_back(b);
    }
    auto freq = counter(nums);
    int one_time, two_times;
    one_time = two_times = 0;
    for (auto item : freq){
        if (item.second == 1){
            one_time++;
        }
        if (item.second == 2){
            two_times++;
        }
    }
    if (one_time == 2 && two_times == 2){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

