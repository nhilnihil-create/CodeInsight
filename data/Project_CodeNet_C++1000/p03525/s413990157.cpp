#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int N;  cin >> N;
    vector<int> D(N+1,0);
    for(int i=1; i<=N; i++)
        cin >> D[i];
    
    vector<int> used(13, 0);
    for(int i=0; i<=N; i++){
        used[D[i]]++;
    }

    if(used[0] > 1 || used[12] > 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1; i<=11; i++){
        if(used[i] > 2){
            cout << 0 << endl;
            return 0;
        }
    }

    vector<int> pos1(24), pos2(24);
    if(used[0]){
        pos1[0] = 1;
        pos2[0] = 1;
    }
    if(used[12]){
        pos1[12] = 1;
        pos2[12] = 1;
    }
    bool right = true;
    for(int i=1; i<=11; i++){
        if(used[i] == 0) continue;
        else if(used[i] == 2){
            pos1[i] = 1;
            pos1[24-i] = 1;
            pos2[i] = 1;
            pos2[24-i] = 1;
        }else {
            if(right){
                pos1[i] = 1;
                pos2[24-i] = 1;
            }else{
                pos1[24-i] = 1;
                pos2[i] = 1;
            }
            right = !right;
        }
    }

    int ans1 = 25;
    for(int i=0; i<24; i++) for(int j=i+1; j<24; j++){
        if(pos1[i] == 0 || pos1[j] == 0) continue;
        ans1 = min(ans1, min(j-i, i+24-j));
    }

    int ans2 = 25;
    for(int i=0; i<24; i++) for(int j=i+1; j<24; j++){
        if(pos2[i] == 0 || pos2[j] == 0) continue;
        ans2 = min(ans2, min(j-i, i+24-j));
    }
    cout << max(ans1, ans2) << endl;
}