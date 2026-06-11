#include <bits/stdc++.h>
using namespace std;

int n, k, q;


int a[2010];
int no[2010];

int solve(){

    priority_queue<int, vector<int>, greater<int>> que;
    vector<int> ans;

    for(int i = 0;i < n;i++){
        if(no[i] == 1){
            while(!que.empty()) que.pop();
        }else{
            que.push(a[i]);
            if(que.size() == k){
                ans.push_back(que.top());
                que.pop();
            }
        }
    }

    if(ans.size() >= q){
        sort(ans.begin(), ans.end());
        return ans[q-1] - ans[0];
    }else{
        return INT_MAX;
    }
}

int main(){
    cin >> n >> k >> q;

    set<int> st;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    int ans = INT_MAX;
    for(auto num : st){
        ans = min(ans, solve());

        for(int i = 0;i < n;i++){
            if(a[i] == num){
                no[i] = 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}