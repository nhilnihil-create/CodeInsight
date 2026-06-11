#include <bits/stdc++.h>
using namespace std;
int h[101];
int main(){
    int n;
    cin >> n;
    int MAX=0;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> h[i];
        MAX=max(h[i],MAX);
    }
    int tmp;
    for(int i=1;i<=MAX;i++){
        if(h[0]>=i)tmp=1;
        else tmp=0;
        for(int j=1;j<n;j++){
            if(h[j-1]<i&&h[j]>=i)tmp++;
        }
        ans+=tmp;
    }
    cout << ans << endl;
}