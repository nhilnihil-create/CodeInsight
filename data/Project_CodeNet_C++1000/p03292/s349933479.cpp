#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main(){
  int a[3];
    for(int i=0; i<3; i++) cin>>a[i];
    sort(a, a+3);
    cout << a[2]-a[0] << endl;
}
