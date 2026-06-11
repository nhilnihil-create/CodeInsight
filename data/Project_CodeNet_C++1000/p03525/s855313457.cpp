#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

map<int, int> mp;

int dfs(int d, multiset<int> &st){
    if(d == 13){
        int mn = 100000000;
        vector<int> vec;

        for(auto it = st.begin(); it != st.end(); it++){
            vec.push_back(*it);
        }

        /*for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << endl;
        */
        int sz = vec.size();
        for(int i = 0; i < sz; i++){
            for(int j = i + 1; j < sz; j++){
                mn = min(mn, min(vec[j] - vec[i], 24 - (vec[j] - vec[i])));
            }
        }

        return mn;
    }

    int ret = 0;

    if(mp[d] >= 3){
        ret = 0;
    }
    else if(mp[d] == 2){
        st.insert(d);
        st.insert(24 - d);
        ret = dfs(d + 1, st);
        auto it = st.find(d);
        st.erase(it);
        it = st.find(24 - d);
        st.erase(it);
    }
    else if(mp[d] == 1){
        st.insert(d);
        int c1 = dfs(d + 1, st);
        st.erase(d);
        st.insert(24 - d);
        int c2 = dfs(d + 1, st);
        st.erase(24 - d);
        ret = max(c1, c2);
    }
    else if(mp[d] == 0){
        ret = dfs(d + 1, st);
    }

    return ret;
}

int main(){
    int N;
    cin >> N;
    int d[N];
    for(int i = 0; i < N; i++) cin >> d[i];

    mp[0]++;
    for(int i = 0; i < N; i++) mp[d[i]]++;

    multiset<int> st;

    cout << dfs(0, st) << endl;
    return 0;
}