#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;


bool C(string& s, int k) {
    int n = s.size();
    set<char> st;
    for(int i = n-k; i < k; ++i) {
        st.insert(s[i]);
    }
    return (st.size() == 1);
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int l = n/2, r = n+1;
    while(r-l > 1) {
        int mid = (l+r)/2;
        if(C(s,mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}