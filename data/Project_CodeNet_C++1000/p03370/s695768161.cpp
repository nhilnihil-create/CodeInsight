#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X; 
    vector<int>m(N);
    int syu = 0;
    for(int i = 0; i < N; i++) {
        cin >> m[i];
        syu += m[i];
    }
    sort(m.begin(),m.end());
    cout << N+(X-syu)/m[0] << endl;
}