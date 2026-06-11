#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a.at(i);
    }
    int odd=0;
    int even=0;
    sort(a.begin(), a.end());
    rep(i,n){
        if(i%2==0) even+=a.at(i);
        else odd+=a.at(i);
    }
    cout << abs(odd-even) << endl;
    return 0;
}