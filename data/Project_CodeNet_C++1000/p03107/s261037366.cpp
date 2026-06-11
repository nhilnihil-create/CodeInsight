#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string S;
    getline(cin, S);

    stack<int> st;
    for (int i = 0; i < S.size(); i++){
        int elem = S[i] - '0';
        if (st.empty() || st.top() == elem)
            st.push(elem);
        else
            st.pop();
    }

    cout << S.size() - st.size() << endl; 

    return 0;
}