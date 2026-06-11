#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<string> st;
    int n; cin >> n;
    bool ok = 1;
    vector<string> vec;
    for(int i = 0; i< n; i++){
        string t; cin >> t;
        if(i == 0){
            vec.pb(t); st.insert(t); continue;
        }
        if(st.find(t) == st.end() && vec[i-1][vec[i-1].length()-1] == t[0]){
            vec.pb(t); st.insert(t);
        }
        else{
            vec.pb(t); st.insert(t);
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
