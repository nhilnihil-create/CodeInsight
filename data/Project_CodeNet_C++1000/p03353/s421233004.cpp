#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    string s; cin >> s;
    int k; cin >> k;
    set<string> st;
    for(int i=0; i<s.size(); ++i){
        for(int j=1; j<=k && i+j<=s.size(); ++j){
            string ss=s.substr(i, j);
            st.insert(ss);
        }
    }
    for(int i=0; i<k-1; ++i){
        st.erase(st.begin());
    }
    cout << *st.begin() << endl;
    return 0;
}
