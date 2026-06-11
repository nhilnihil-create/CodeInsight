#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    set<string> st;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= k && j + i <= n; j++){
            st.insert(s.substr(i, j));
        }
    }
    int count = 0;
    //cout << st.size() << endl;
    for (auto it = st.begin(); it != st.end(); it++){
        count++;
        //cout << *it << endl;
        if (count == k){
            cout << *it << endl;
            break;
        }
    }
    return 0;
}