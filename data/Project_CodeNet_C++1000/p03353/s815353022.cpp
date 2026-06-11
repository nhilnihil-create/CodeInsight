#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;

    set<string> st;
    
    for(int i=1; i<=k; i++){
        for(int j=0; j<s.size()-i+1; j++){
            st.insert(s.substr(j,i));
        }
    }
    int count = 0;
    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        count++;
        if(count == k) std::cout << *itr << "\n";
    }
    return 0;
}