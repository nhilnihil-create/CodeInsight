#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    string s;
    cin >> s;
    set<string> st;
    st.insert("KIHBR");
    st.insert("AKIHBR");
    st.insert("KIHABR");
    st.insert("AKIHABR");
    st.insert("KIHBAR");
    st.insert("AKIHBAR");
    st.insert("KIHABAR");
    st.insert("AKIHABAR");
    st.insert("KIHBRA");
    st.insert("AKIHBRA");
    st.insert("KIHABRA");
    st.insert("AKIHABRA");
    st.insert("KIHBARA");
    st.insert("AKIHBARA");
    st.insert("KIHABARA");
    st.insert("AKIHABARA");
    if(st.find(s) != st.end()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}