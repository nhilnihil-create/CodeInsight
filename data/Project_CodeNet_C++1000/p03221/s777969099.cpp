#include <bits/stdc++.h>
using namespace std;

typedef struct str_pref pref_t; 
typedef struct str_pref {
    vector<int> city;
} pref_t;
int main(void) {
    int N,M,P,Y;
    ostringstream oss;

    cin >> N >> M;

    vector<pref_t> pref(N);
    vector<string> id(M);
    vector<tuple<int,int,int>> py(M);
    for(int i=0;i<M;i++) {
        cin >> P >> Y;
        py[i] = make_tuple(Y,P,i);
    }

    sort(py.begin(), py.end());
    for(int i=0;i<M;i++) {
        P = get<1>(py[i]);
        Y = get<0>(py[i]);
        oss.str("");        
        oss << setw(6) << setfill('0') << P;
        P--;
        oss << setw(6) << setfill('0') << (pref[P].city.size()+1);
        id[get<2>(py[i])] = oss.str();
        pref[P].city.push_back(i);
    }

    for(auto s:id) {
        cout << s << endl;
    }
    return 0;
}
