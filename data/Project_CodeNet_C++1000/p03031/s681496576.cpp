#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
 
    vector<vector<int>> s(m);
    for(int i=0; i<m;i++) {
       int k;
       cin>>k;
       s[i].resize(k);
      for (int j=0; j<k;j++) {
            cin>>s[i][j];
            s[i][j]-=1;
        }
    }
 
    vector<int>p(m);
    for (int i=0;i<m;i++) cin >> p[i];
 
    long long sum = 0;
    for (int x=0; x<1<<n;x++) {int num = 0;
     for(int i=0;i<m;i++) {
     int st = 0;
      for (int j=0;j<s[i].size(); j++) {
           if(x >> s[i][j]&1) 
               st++;
        }
       if (st%2==p[i]) {
                num++;
            }
        }
        if (num==m)sum++;
    }
 
    cout<<sum<<endl;
 
}
