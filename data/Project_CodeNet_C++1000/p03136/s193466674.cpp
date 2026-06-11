#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    int goukei = 0;
    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;
        cnt = max(cnt,L);
        goukei += L;
    }
    if(cnt < goukei-cnt) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
