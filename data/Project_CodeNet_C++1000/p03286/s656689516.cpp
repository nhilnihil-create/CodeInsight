#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> st;
    int n; cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    while(n){
        int rem = n&1;
        st.push(rem);
        n -= rem;
        n /= -2;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
    return 0;
}
//Saw the solution video