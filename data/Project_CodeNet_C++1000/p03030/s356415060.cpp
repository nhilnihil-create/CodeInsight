#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
    cin >> N;
    
    vector<tuple <string,int,int>> t(N);
    for (int i=0;i<N;i++) {
        string a;
        int b;
        cin >> a >> b;
        t.at(i) = make_tuple(a,-b,i+1);
    }
    sort(t.begin(),t.end());
    
    for (int j=0;j<N;j++) {
        string a;
        int b,i;
        tie(a,b,i) = t.at(j);
        cout << i << endl;
    }
   }

 