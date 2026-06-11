#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int N, K;
    string s;
    cin >> N >> K >> s;

    vector<int> Nums;
    int now = 1;
    int cnt = 0;
    rep(i, N){
        if(s[i] == (char)('0' + now)) cnt++;
        else {
            Nums.push_back(cnt);
            now = 1 - now;
            cnt = 1;
        }
    }
    if (cnt != 0) Nums.push_back(cnt);

    if(Nums.size() % 2 == 0) Nums.push_back(0);

    int Add = 2 * K + 1;
    
    int ans = 0;

    int left = 0;
    int right = 0;
    int tmp = 0;
    
    for (int i = 0; i < Nums.size(); i += 2) {
        int Nextleft = i;
        int Nextright = min(i + Add, (int)Nums.size());

        while (Nextleft > left) {
            tmp -= Nums[left];
            left++;
        } 
        
        while (Nextright > right) {
            tmp += Nums[right];
            right++;
        }
        ans = max(tmp, ans);
    }

    cout << ans << endl;
}