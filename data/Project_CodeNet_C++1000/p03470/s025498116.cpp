#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, d;
    cin >> N;
    set<int> st;
    for(int i = 0; i < N; ++i){
        cin >> d;
        st.insert(d);
    }
    cout << st.size() << "\n";

}