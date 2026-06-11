#include <iostream>
#include <set>
using namespace std;
int main(){
    set<char> st;
    for(int i = 0; i < 3; i++){
        char c; cin >> c;
        st.insert(c);
    }
    if(st.count('a') == 1 && st.count('b') == 1 && st.count('c') == 1) puts("Yes");
    else puts("No");
    return 0;
}