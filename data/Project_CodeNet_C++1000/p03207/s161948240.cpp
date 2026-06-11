#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    int s = 0;
    for(int i=0;i<n;i++){
        cin >> p[i];
        s += p[i];
    }
    sort(p.begin(),p.end(),greater<int>());

    cout << s - p[0] / 2 << endl;
    
}