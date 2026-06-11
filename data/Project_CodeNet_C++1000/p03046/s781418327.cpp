#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int m, k;
    cin >> m >> k;
    int n=1;
    for(int i=0;i<m;++i)n<<=1;
    if(k >= n){
        cout << -1 << endl;
    }else if(k == 0){
        for(int i=0;i<n;++i){
            if(i)cout << " ";
            cout << i << " " << i;
        }
        cout << endl;
    }else if(n <= 2){
        cout << -1 << endl;
    }else{
        deque<bool> used(n);
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(used[i])continue;
            int j = i ^ k;
            ans.push_back(i);
            ans.push_back(j);
            used[i] = true;
            used[j] = true;
            int a = i + 1;
            while(a < n && used[a])a++;
            int b = a ^ k;
            if(j >= n || a >= n || b >= n){
                cout << -1 << endl;
                return 0;
            }
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(j);
            ans.push_back(i);
            ans.push_back(b);
            ans.push_back(a);
            used[a] = true;
            used[b] = true;
        }

        for(int i=0;i<(int)ans.size();++i){
            if(i)cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}