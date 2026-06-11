#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> d(n);
    for(int i=0; i<n; i++){
        cin >> d.at(i);
    }
    int m;
    cin >> m;
    vector<int> t(m);
    for(int i=0; i<m; i++){
        cin >> t.at(i);
    }

    sort(d.begin(),d.end());
    sort(t.begin(),t.end());

    int i=0,j=0;
    while(1){
        if(j==m){
            cout << "YES" << endl;
            break;
        }
        if(i==n){
            cout << "NO" << endl;
            break;
        }
        if(d.at(i)==t.at(j)) j++;
        i++;
    }
}