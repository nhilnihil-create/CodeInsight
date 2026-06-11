#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;

    if(N>=M){
        cout << "0" << endl;
        return 0;
    }

    vector<int> x(M);
    
    for(int i=0; i<M; i++){
        cin >> x.at(i);
    }

    sort(x.begin(),x.end());

    vector<int> L(M-1);

    for(int i=0; i<M-1; i++){
        L.at(i) = x.at(i+1) - x.at(i);
    }
    
    sort(L.begin(),L.end());

    int ans =0;
    for(int i=0; i<M-N; i++){
        ans += L.at(i);
    }

    cout << ans << endl;
}