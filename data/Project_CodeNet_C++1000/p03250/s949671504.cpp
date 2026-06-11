#include <bits/stdc++.h>
using namespace std;
int main(void){
    int nums[3];
    for (int i=0; i<3; i++) cin >> nums[i];
    sort(nums, nums+3);
    cout << nums[2]*10 + nums[1] + nums[0] << endl;
    return 0;
}
