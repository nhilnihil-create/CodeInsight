#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    set<string> st;
    vector<string> vec;
    for(int i=0; i < n; ++i){
        string w; cin >> w;
        if(st.count(w) == 1){
            puts("No");
            return 0;
        }
        if(vec.size() != 0){
            string s = vec[vec.size()-1];
            if(s[s.size()-1] != w[0]){
                puts("No");
                return 0;
            }
        }
        st.insert(w); vec.push_back(w);
    }
    puts("Yes");
    return 0;
}