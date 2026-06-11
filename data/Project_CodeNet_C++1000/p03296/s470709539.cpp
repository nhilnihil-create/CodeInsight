#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N,ans=0,now=0; cin >> N;
    int data[N];
    for(int i=0;i<N;i++) cin >> data[i];
    now = data[0];
    
    for(int i=1;i<N;i++){
        if(data[i] == now){ ans++; i++; }
        now = data[i];
    }
    cout << ans << endl;
}