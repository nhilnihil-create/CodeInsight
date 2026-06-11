#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;


int main()
{
    int n;
    cin >> n;

    string a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    rep(i, n){
        set<char> st;
    
        st.insert(a[i]);
        st.insert(b[i]);
        st.insert(c[i]);
        if(st.size() == 2){
            ans++;
        }else if(st.size() == 3){
            ans += 2;
        }
    }

    cout << ans << "\n";

    return 0;
}
