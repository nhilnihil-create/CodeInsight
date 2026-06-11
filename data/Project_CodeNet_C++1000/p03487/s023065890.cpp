#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    long long A;
    map<long long,int> mp;
    set<long long> st;
    for(int i = 0; i < N;i++){
        cin >> A;
        mp[A]++;
        st.insert(A);
    }
    int sum = 0;
    for(auto itr = st.begin(); itr != st.end(); ++itr){
        if(mp[*itr]==0)continue;
        else if(mp[*itr]-*itr >= 0)sum += mp[*itr] - *itr;
        else sum +=mp[*itr];
    }
    cout << sum <<endl;
    
    
    
    
}
