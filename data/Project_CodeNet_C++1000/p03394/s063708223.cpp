#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N; cin >> N;
    if(N == 3) cout << "2 5 63" << endl;
    else{
        vector<int> ans;
        ans.push_back(3); ans.push_back(9); ans.push_back(2); ans.push_back(4);
        for(int i = 5; i <= min(15002, N); i++){
            if(i % 3 == 2){
                ans.push_back(ans.back()+2);
            }
            else if(i % 3 == 0){
                int val = ans.back();
                ans.pop_back();
                ans.push_back(val+2);
                ans.push_back(val+4);
            }
            else{
                ans.insert(ans.end()-2, ans.back()-4);
            }
        }
        if(N > 15002 && N % 2 == 1) ans.pop_back();
        int val = 9;
        for(int i = ans.size()+2; i <= N; i+=2){
            ans.push_back(val+6);
            ans.push_back(val+12);
            val += 12;
        }
        rep(i, ans.size()) cout << ans[i] << " "; cout << endl;
    }
    return 0;
}