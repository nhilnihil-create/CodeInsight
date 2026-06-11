#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;


int main(){
    int N; cin >> N;
    set<int> st;
    for(int i=0; i<N; i++){
        int d; cin >> d;
        st.insert(d);
    }

    cout << st.size() << endl;
    return 0;
}