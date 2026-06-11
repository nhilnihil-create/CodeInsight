#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    vector<int> b(N);
    for (int i=0; i<N; i++) {cin >> b[i]; b[i]--;}
    
    vector<int> ans;
    int k=b.size();
    while(k > 0){ 
        int pos = -1;
        for (int i=b.size() - 1; i >= 0; i--){
            if(b[i] == i){
                pos = i;
                
                break;
            }
        }
        // 
        if (pos == -1) {cout << -1 << endl; return 0;}
        ans.push_back(pos + 1);
        b.erase(b.begin() + pos);
        k--;
    }
    reverse(ans.begin(), ans.end());
    for (auto it: ans){
        cout << it << endl;
    }
}
