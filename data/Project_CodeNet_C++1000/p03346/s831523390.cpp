#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    int index[n+1];
    index[0] = 0;
    for(int i=0; i<n; i++){
        cin >> p[i];
        index[p[i]] = i+1;
    }
    int t = 0;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(index[i] > index[i-1]){
            cnt++;
        }
        else{
            t = max(t,cnt);
            cnt = 1;
        }
    }
    t = max(t,cnt);
    cout << n-t << endl;
    return 0;
}
