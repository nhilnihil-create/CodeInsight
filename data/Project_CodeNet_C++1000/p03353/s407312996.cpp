#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    set<string> st;
    for(int i=1;i<=5;++i){
        for(int j=0;j<s.size();++j){
            if(j+i > s.size())break;
            st.insert(s.substr(j, i));
        }
    }

    auto ans = st.begin();
    for(int i=1;i<k;++i)ans++;
    cout << *ans << endl;

    return 0;
}