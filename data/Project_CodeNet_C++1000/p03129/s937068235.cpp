    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
      int a,b;
      cin >> a >> b;
      if(a%2==0){
        if(b<=a/2){cout << "YES" << endl;}
        else cout << "NO" << endl;
      }else{
        if(b<=1+(a/2)){cout << "YES" << endl;}
        else cout << "NO" << endl;
      }
      return 0;
    }