#include <bits/stdc++.h>
using namespace std;
int ans[31];
int main(){
    int n,m;
    cin >> n >> m;
    int k;
    int a;
    for(int i=0;i<n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> a;
            ans[a-1]++;
        }
    }
    int count=0;
    for(int i=0;i<m;i++)if(ans[i]==n)count++;
    cout << count << endl;
}