#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin >> b.at(i);
    }
    vector<int> a(m);
    int ans = 0;
    int count = 0;
    for(int k=0; k<n; k++){
        for(int j=0; j<m; j++){
            cin >> a.at(j);
            ans += a.at(j)*b.at(j);
        }
        ans += c;
        if(ans > 0){
            count += 1;
        }
        ans = 0;
    }
    cout << count << endl;
}