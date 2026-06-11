#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s.at(i);
    }

    int m;
    cin >> m;
    vector<string> t(m);
    for(int i=0; i<m; i++){
        cin >> t.at(i);
    }

    int count=1;
    int ans=0;
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>0; j--){
            if(s.at(i)==s.at(j)) count++;
        }
        for(int j=0; j<m; j++){
            if(s.at(i)==t.at(j)) count--;
        }
        ans=max(count,ans);
        count=0;
    }   
    cout << ans <<endl;
//    if(s.at(0)==s.at(2)) cout << 1 << endl;
}