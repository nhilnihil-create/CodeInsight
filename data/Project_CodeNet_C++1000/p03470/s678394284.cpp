#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool moti[110]={};
    for(int i=0; i<n; i++) {
        int d;
        cin >> d;
        moti[d] = true;
    }
    int cnt = 0;
    for(int i=0; i<105; i++){
        if(moti[i])cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
