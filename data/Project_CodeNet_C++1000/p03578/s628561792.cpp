#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N; cin >> N;
    map<int,int> m{};
    for(int i=0;i<N;i++){int n; cin >> n; m[n]++;}
    int M; cin >> M;
    for(int i=0;i<M;i++){int n; cin >> n; m[n]--;}
    string ans="YES";
    for(auto i=m.begin(); i!=m.end();i++){
        int n = i->second;
        if(n<0) {ans="NO"; break;}
    }
    cout << ans << endl;
}
