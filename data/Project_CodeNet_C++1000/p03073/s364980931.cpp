#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    cin >> S;

    vector<int> count(2,0);
    for(int j : {0, 1}){
        int target = j;
        for(int i=0; i<S.size(); i++){
            int val = S[i] - '0';
            if(target == val){
                count[j] += 1;
            }
            target = (target == 0)? 1:0;
        }
    }
    int ans = *min_element(count.begin(), count.end());
    cout << ans << endl;
    return 0;
}