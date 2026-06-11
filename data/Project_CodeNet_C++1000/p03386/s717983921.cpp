#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,K;
    cin >> A >> B >> K;
    set<int> st;
    for(int i=A;i<=min(A+K-1,B);++i){
        st.insert(i);
    }

    for(int i=max(B-(K-1),A);i<=B;++i){
        st.insert(i);
    }
    
    for(auto e:st){
        cout << e << endl;
    }
}
