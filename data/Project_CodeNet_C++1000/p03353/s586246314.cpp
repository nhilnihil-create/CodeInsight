#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string str;
    int K;
    cin >> str;
    cin >> K;
    set<string> st;
    for(int i=0; i<str.size(); i++) {
        for(int j=i+1; j<=min((int)str.size(), i+K); j++) {
            int cnt=0;
            bool if_break=false;
            if(st.size()<K) {
                st.insert(str.substr(i, j-i));
            } else {
                for(auto itr=st.begin(); itr!=st.end(); itr++) {
                    if(cnt<=K) {
                        if(*itr>str.substr(i, j-i)) {
                            st.insert(str.substr(i, j-i));
                            break;
                        }
                    } else {
                        if_break=true;
                        break;
                    }
                    cnt++;
                }
            }
            if(if_break) break;
        }
    }
    
    int idx=1;
    for(auto itr=st.begin(); itr!=st.end(); itr++) {
        if(idx==K) {
            cout << *itr << endl;
            break;
        }
        idx++;
    }


    return 0;
    
}