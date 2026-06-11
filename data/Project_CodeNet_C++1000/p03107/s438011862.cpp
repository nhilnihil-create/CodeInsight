#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    string t;
    cin >> t;
    stack<char> s;
    int sum = 0;
    for(int i = 0;i < t.size();i++){
        if(s.empty() || s.top() == t[i])s.push(t[i]);
        else {
            sum += 2;
            s.pop();
        }
    }
    cout << sum << endl;
}