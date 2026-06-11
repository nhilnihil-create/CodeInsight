#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<tuple<string,int,int>> p(N);
    for (int i=0;i<N;i++){
        string S;
        int q;
        cin >> S >> q;
        p.at(i) = make_tuple(S,-q,i+1);
    }
    sort(p.begin(),p.end());
    
    for (int i=0;i<N;i++){
        int j;
        tie(ignore,ignore,j) = p.at(i);
        cout << j << endl;
    }
}