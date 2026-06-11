#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    
    int N; cin >> N;
    int data[N],list[N];
    for(int i=0;i<N;i++){int a;cin >> a; data[i] = a; list[i] = a;}
    sort(data,data+N);
    int l,r;
    l = data[(N-1)/2];
    r = data[N/2];
    for(int i=0;i<N;i++){
        if(list[i] <= l) cout << r <<endl;
        else cout << l << endl;
    }
}