#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,A,B; cin >> N >> A >> B;
    int cnt0=0,cnt1=0,cnt2=0;
    for (;N--;){
        int P; cin >> P;
        if (P<=A) ++cnt0;
        else if (P<=B) ++cnt1;
        else ++cnt2;
    }
    cout << min({cnt0,cnt1,cnt2}) << '\n';
}