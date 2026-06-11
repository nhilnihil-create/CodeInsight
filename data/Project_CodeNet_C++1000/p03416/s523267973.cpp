#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        int a,b;
        cin >> a >> b;
        int n=b-a;
        int cunt=0;
        for(int i=a;i<=b;i++){
          int s= i%10,t=i/10000%10;
          int u= i/10%10,v=i/1000%10;
          if(s==t&&u==v)cunt++;
          
        }
        cout << cunt << endl;
        return 0;
    }
