#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        a.at(i) -= i+1;
    }
    sort(a.begin(), a.end());
    ll ans=pow(10,18);
    int s;
    s=a.at(n/2);
    ll cnt=0;
    for(int i=0; i<n; i++){
        cnt+=(ll)abs(s-a.at(i));
    }
    cout << cnt << endl;
}