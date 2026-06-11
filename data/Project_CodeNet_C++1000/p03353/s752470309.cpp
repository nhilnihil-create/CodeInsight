#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

int main(void){

    string S; cin>>S;
    int K; cin>>K;
    set<string> st;
    for (int i = 0; i < S.length(); ++i) {
        for (int j = 0; j < K; ++j) {
            st.insert(S.substr(i,j+1));
        }
    }
    auto itr=st.begin();
    for (int i = 0; i < K-1; ++i) {
        itr++;
    }

    cout<<*itr<<endl;
}