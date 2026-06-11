#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N; 
    vector<int>a(N);
    map<int,int>Map;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        Map[a[i]]++;
    }
    int ans = 0;
    for(auto x:Map) {
        int X = x.first;
        int Y = x.second;
        if(X <= Y) {
            ans+=(Y-X);
        }
        else {
            ans+=Y;
        }
    }
    cout <<  ans << endl;
}
