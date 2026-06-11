#include <bits/stdc++.h>
 #define rep(i,n) for(int i=0;i<n;i++)
 using namespace std;
  int main(){
      vector<int> a(8);
      rep(i,6){
          cin >> a[i];
      }
      vector<int> b(4);
    rep(i,6){
        rep(j,6){
            if(a[i]==a[j]){
                b[a[i]]++;
                break;
            }
        }
    if(b[a[i]]>=3){
        cout << "NO" << endl;
       //cout << a[i] << " " <<  b[a[i]] << endl;
        break;
    }
    if(i+1==6){
        cout << "YES" << endl;
        break;
    }
    }
    return 0;

  }