#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(!st.empty() && st.top()!=s[i])
        {
            st.pop();
            cnt += 2;
        }
        else
        {
            st.push(s[i]);
        }
    }
    cout << cnt << endl;
    return 0;
}