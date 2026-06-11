#include <iostream>
#include <set>
using namespace std;
int collatz(int x){
    if(x%2 == 0) return x/2;
    else return 3*x+1;
}
int main(){
    int s; cin >> s;
    set<int> st;
    int ans = 1;
    while(1){
        st.insert(s);
        s = collatz(s);
        ans++;
        if(st.count(s) == 1) {
            cout << ans << endl;
            break;
        }
    }
    return 0;
}