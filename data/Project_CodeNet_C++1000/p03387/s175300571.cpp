#include <bits/stdc++.h>
using namespace std;

int main(void){
    int nums[3], cnt = 0;
    for (int i=0; i<3; i++) cin >> nums[i];
    sort(nums, nums+3, greater<int>());
    cnt += (nums[0] - nums[1]) / 2;
    cnt += (nums[0] - nums[2]) / 2;
    if ((nums[0]-nums[1])%2 == 1 && (nums[0]-nums[2])%2 == 1) cnt++;
    else if ((nums[0]-nums[1])%2 == 1 || (nums[0]-nums[2])%2 == 1) cnt+=2;
    cout << cnt << endl;
    return 0;
}