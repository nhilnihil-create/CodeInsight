#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin >> x.at(i);
        c.at(i) = x.at(i);
    }
    sort(c.begin(),c.end());
    int a,b;
    a=c.at(n/2-1);
    b=c.at(n/2);
    for(int i=0; i<n; i++){
        if(x.at(i) <= a) cout << b << endl;
        else cout << a << endl;
    }
}