#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string str;
    cin >> str;
    int ans=0;
    vector<int> vec;
    char cur_s=str[0];
    int cnt=1;
    for(int n=1; n<N; n++) {
        if(cur_s==str[n]) {
            cnt++;
        } else {
            vec.push_back(cnt);
            cnt = 1;
            cur_s = str[n];
        }
    }
    vec.push_back(cnt);
    vector<int> s_vec(vec.size()+1, 0);
    for(int i=0; i<vec.size(); i++) {
        s_vec[i+1] = vec[i]+s_vec[i];
    }

    for(int i=0; i<vec.size(); i++) {
        if(str[0]=='1') {
            if(i%2) {
                ans = max(ans, s_vec[(int)min(i+K*2, (int)s_vec.size()-1)]-s_vec[i]);
            } else {
                ans = max(ans, s_vec[(int)min(i+K*2+1, (int)s_vec.size()-1)]-s_vec[i]);
            }
        } else {
            if(i%2==0) {
                ans = max(ans, s_vec[(int)min(i+K*2, (int)s_vec.size()-1)]-s_vec[i]);
            } else {
                ans = max(ans, s_vec[(int)min(i+K*2+1, (int)s_vec.size()-1)]-s_vec[i]);
            }
        }
    }
    cout << ans << endl;
    

    return 0;
    
}