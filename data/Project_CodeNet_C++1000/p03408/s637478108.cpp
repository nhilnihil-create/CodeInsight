#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>

using namespace std;

int main() {
    int n, m; cin >> n;
    vector<string> s(n);
    vector<string> t(m);
    map<string, int> st;
    set<string> d1;
    set<string> d2;

    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
        d1.insert(s[i]);
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        std::cin >> t[i];
        d2.insert(t[i]);
    }

    for (auto itr = d1.begin(); itr != d1.end(); itr++)
    {
        st.insert(make_pair(*itr, 0));
    }

    for (auto itr = d2.begin(); itr != d2.end(); itr++)
    {
        if(d1.find(*itr) != d1.end()) {
          st.insert(make_pair(*itr, 0));
        }
    }

    for (int i = 0; i < n; i++)
    {
        st[s[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        st[t[i]]--;
    }

    int max = 0;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        max = std::max(max, itr->second);
    }

    std::cout << max << std::endl;
}




