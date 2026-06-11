#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;


int main() {
    int N;
    cin>>N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());

    int a1=a[0],a2,dist=2e9+5;

    for (int i = 1; i < N; ++i) {
        if(abs(a[i]*2-a1)<dist){
            dist=abs(a[i]*2-a1);
            a2=a[i];
        }
    }
    cout<<a1<<" "<<a2<<endl;
    return 0;
}