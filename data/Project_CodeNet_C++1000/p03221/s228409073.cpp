#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
typedef pair<int, int> P;
int main(){
    int N, M;
    cin >> N >> M;
    vector<P> Y(M);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        Y[i] = P(a, b);
    }
    int cnt = 1;
    vector<int> ind(M);
    for(int i = 0; i < M; i++){
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](int i, int j){
        if(Y[i].first != Y[j].first)return Y[i].first < Y[j].first;
        return Y[i].second < Y[j].second;
    });
    vector<string> ans(M);
    for(int i = 0; i < M; i++){
        string s1 = "000000", s2 = "000000";
        P v = Y[ind[i]];
        string t1 = to_string(cnt);
        string t2 = to_string(v.first);
        int te = 6;
        for(int i = 0; i < t1.size(); i++){
            s2[te - t1.size() + i] = t1[i];
        }
        for(int i = 0; i < t2.size(); i++){
            s1[te - t2.size() + i] = t2[i];
        }
        ans[ind[i]] = s1 + s2;
        if(i != M - 1 && Y[ind[i]].first == Y[ind[i + 1]].first) cnt++;
        else cnt = 1;
    }
    for(int i = 0; i < M; i++){
        cout << ans[i] << endl;
    }
}