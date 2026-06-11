#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n_1, n_2, n_3, n_4;cin>>n_1>>n_2>>n_3>>n_4;
    vector<int> nums{n_1, n_2, n_3, n_4};

    sort(nums.begin(), nums.end());
    vector<int> expected{1, 4, 7, 9};
    bool judge = true;

    for (int i=0;i<4;i++){
        if (nums[i] != expected[i]){
            judge = false;
            break;
        }
    }
    if (judge){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
    
}
