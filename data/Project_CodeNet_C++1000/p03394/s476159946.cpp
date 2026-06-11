#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    set<int> st;
    if(n < 6){
        st = set<int>({2, 3, 25});
        for(int i=1;st.size()<n;++i)st.insert(30*i);
    }else{
        int sum = 0;
        for(int i=0;st.size()<n;++i){
            st.insert(6*i+2);
            sum += 6*i+2;
            if(st.size() >= n)break;
            st.insert(6*i+3);
            sum += 6*i+3;
            if(st.size() >= n)break;
            st.insert(6*i+4);
            sum += 6*i+4;
            if(st.size() >= n)break;
            st.insert(6*i+6);
            sum += 6*i+6;
        }
        if(sum % 6 == 2){
            st.erase(8);
            st.insert(30000);
        }else if(sum % 6 == 3){
            st.erase(9);
            st.insert(30000);
        }else if(sum % 6 == 5){
            st.erase(9);
            st.insert(29998);
        }
    }
    vector<int> v(st.begin(), st.end());
    for(int i=0;i<n;++i){
        if(i)cout << " ";
        cout << v[i];
    }
    cout << endl;

    return 0;
}
