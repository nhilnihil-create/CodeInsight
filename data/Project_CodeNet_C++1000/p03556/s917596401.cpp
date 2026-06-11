#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n, i=0;
    cin >> n;
      while(1){
        int tmp = sqrt(n-i);
        if(n-i == tmp*tmp) break;
        i++;
      }
      cout << n-i << endl;
}
