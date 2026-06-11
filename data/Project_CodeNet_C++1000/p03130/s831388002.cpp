#include<bits/stdc++.h>
using namespace std;

int main(){
    int count[4];
    memset(count,0,sizeof(count));
    for(int i=0;i<3;i++){
        int a,b;cin >> a >> b;a--,b--;
        count[a]++;
        count[b]++;
    }
    int s = 0;
    for(int i=0;i<4;i++){
        if(count[i]==1) s++;
    }
    if(s==2) cout << "YES" << endl;
    else cout << "NO" << endl;
}