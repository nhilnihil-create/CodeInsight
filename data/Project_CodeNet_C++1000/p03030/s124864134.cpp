#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<tuple<string,int,int>>t;
    for(int i=0;i<N;i++){
        string A;
        int B;
        cin >> A>>B;
        B=-B;
        t.push_back(make_tuple(A,B,i+1));
    }
    sort(t.begin(),t.end());
    for(int i=0;i<N;i++){
        cout<<get<2>(t.at(i))<<endl;
    }


}