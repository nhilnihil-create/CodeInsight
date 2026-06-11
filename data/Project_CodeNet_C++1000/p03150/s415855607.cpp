#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n=s.size(),flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;i+j-1<n;j++){
            string t = s;
            t.erase(i,j);
            if(t=="keyence") flag  = 1;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
