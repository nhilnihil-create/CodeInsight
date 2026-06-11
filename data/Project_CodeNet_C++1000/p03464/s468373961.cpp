#include<bits/stdc++.h>
using namespace std;

int main(){
    int K; cin >> K;
    int a[K];
    for(int i=0;i<K;i++) cin >> a[i];
    reverse(a,a+K);
    long long a_max=2;
    long long a_min=2;
    for(int i=0;i<K;i++){
        a_max=(a_max/a[i]+1)*a[i]-1;
        a_min=((a_min+a[i]-1)/a[i])*a[i];
        if(a_min>a_max){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << a_min << " " << a_max << endl;
}