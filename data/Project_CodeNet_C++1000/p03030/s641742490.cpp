#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<tuple<string,int,int>> res(N);
    for(int i=0; i<N; i++){
        string S; int P;
        cin >> S >> P;
        res.at(i)=make_tuple(S,100-P,i+1);
    }
    sort(res.begin(),res.end());
    for(int i=0; i<N; i++){
        int n;
        tie(ignore,ignore,n)=res.at(i);
        cout << n << endl;
    }
}