#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> vec(M);

    for(int i=0; i<M; i++){
        int min, max;
        cin >> min >> max;

        vec[i] = make_pair(max, min);
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    int just_max;

    for(int i=0; i<M; i++){
        if(vec[i].second >= just_max || i==0){
            just_max = vec[i].first;
            ans++;
        }
    }

    cout << ans << endl;

}