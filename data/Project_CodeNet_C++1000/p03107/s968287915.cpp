#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
int main(void){
    string S;
    cin >> S;
    stack<char> stacks;
    int ans=0;
    stacks.push(S[0]);
    for(int i=1;i<S.length();i++){
        if(!stacks.empty() && stacks.top() != S[i]){
            ans += 2;
            stacks.pop();
        }
        else{
            stacks.push(S[i]);
        }
    }
    
    cout << ans << endl;
    
}
