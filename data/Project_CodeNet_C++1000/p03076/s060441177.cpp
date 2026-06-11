#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    vector<int> nums = {a,b,c,d,e};
    vector<bool> last(5,0);
    int minim = 9;
    for (int i=0; i<5; i++) if (nums[i]%10>0 && nums[i]%10<minim) minim = nums[i]%10;
    for (int i=0; i<5; i++) if (nums[i]%10==minim) {
        last[i] = true;
        break;
    }
    int res = 0;
    for (int i=0; i<5; i++) if (!last[i] && nums[i]%10>0) nums[i] = nums[i]/10*10+10;
    for (auto i : nums) res+=i;
    cout << res;
    return 0;
}