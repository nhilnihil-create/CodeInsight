#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int a,b,x;
    cin >> a >> b >> x;
    int first = x;
    int second = x;
    set<int> st;
    for(int i=a;first && i<=b; first--, i++){
        st.insert(i);
    }
    for(int i=b;second && i>=a; second--, i--){
        st.insert(i);
    }
    for(auto it=st.begin(); it!= st.end(); it++){
        cout << *it <<endl;
    }
}