#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;


int main() {
    int s;
    cin >> s;
    set<int> st;
    st.insert(s);
    rep(i,1e9){
        if(s%2==0){
            s/=2;
        }else{
            s = 3*s +1;
        }
        if(st.count(s)){
            cout << i+2 << endl;
            return 0;
        }
        st.insert(s);
    }
    return 0;
}