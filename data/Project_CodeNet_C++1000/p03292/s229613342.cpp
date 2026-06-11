#include <bits/stdc++.h>
using namespace std;

int main(){
    /*
    vector<int> a(3);
    for(int i=0; i<3; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[2]-a[0] << endl;
    */
   vector<int> a(3);
   for(int i=0; i<3; ++i){
       cin >> a[i];
   }
   sort(a.begin(), a.end());
   int sum=0;
   sum += a[2] - a[1] + a[1] - a[0];
   cout << sum << endl;
}
