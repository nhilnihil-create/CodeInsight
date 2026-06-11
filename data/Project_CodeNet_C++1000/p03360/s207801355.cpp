#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> nums(3);
    int k;
    for (int i=0; i<3; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    cin >> k;
    for (int i=0; i<k; i++) nums[2] *= 2;
    cout << accumulate(nums.begin(), nums.end(), 0) << endl;
    return 0;
}