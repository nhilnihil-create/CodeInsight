#include<iostream>
#include<vector>
#include<string>
#include<stack>


// ref : https://drken1215.hatenablog.com/entry/2019/03/03/224100

int main(){
    std::string S;
    std::cin >> S;
    std::stack<char> st;

    int ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(st.empty() || st.top() == S[i]){
            st.push(S[i]);
        }else{
            st.pop();
            ans++;
        }
    }

    std::cout << 2 * ans << std::endl;
    return 0;
}
