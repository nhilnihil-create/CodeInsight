#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > ba(M);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        ba[i] = make_pair(b, a);
    }

    sort(ba.begin(), ba.end());
    int cur = 1e9;
    int res = 0;
    for(int i=0; i<M; i++){
        if(cur < ba[i].second || ba[i].first <= cur){
            cur = ba[i].first - 1;
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
