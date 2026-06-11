#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i=0;i<N;i++) {
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    
    int count=1;
    int point=0;
    for (int i=0;i<N;i++) {
        if(count%2 ==1) {
            point += a[i];
        }
        else {
            point -= a[i];
        }
        count++;
    }
    cout << point << endl;
    
   }

 