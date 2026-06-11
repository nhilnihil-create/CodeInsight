#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string s;
    int k;
    cin >> s >> k;
    set<string>st;
    int l = s.size();
    rep(i,l){
        for(int j=1;j+i<=l;j++){
            if(j>5)continue;
            string now = s.substr(i,j);
            st.emplace(now);
        }
    }
    auto itr=st.begin();
    rep(i,k-1){
        itr++;
    }
    cout << *itr << endl;
    return 0;
}