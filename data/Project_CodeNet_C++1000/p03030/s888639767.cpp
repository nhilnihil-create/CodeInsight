#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<tuple<string,int,int>> dic;
    string S;
    int P;
    for ( int i = 0; i < N; ++i){
        cin >> S >> P;
        dic.push_back(make_tuple(S,-P,i+1));
    }
    
    sort(dic.begin(),dic.end());
    for ( auto a: dic){
        int x;
        tie (S,P,x) = a;
        cout << x << endl;
    }
    
    return 0;
}
