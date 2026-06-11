#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int main(){
    int k, i, j;
    vector<string> v;
    set<string> st;
    string s;
    cin >> s >> k;
    for(i=0; i<s.length(); i++){
        for(j=0; j<k && i+j<s.length(); j++){
            v.push_back(s.substr(i, j+1));
        }
    }
    sort(v.begin(), v.end());
    i = 0;
    while(st.size() < k){
        st.insert(v[i]);
        i++;
    }
    cout << v[i-1] << "\n";
    return 0;
}