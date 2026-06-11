#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n],s1=0,s2=0;
    for(int i=0; i<n; i++)
       cin >> a[i];
    sort(a,a+n,greater<int>());
    for(int i=0; i<n; i++){
       if(i%2==0)
         s1+=a[i];
       else 
         s2+=a[i];
    }
    cout << s1-s2 << endl;
    return 0;
}