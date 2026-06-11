    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int N;
      cin >> N;
      int k=N;
      int f=0;
      
      // ここにプログラムを追記
      for(int i=9;i>0;i--){
        if(k/(int)pow(10,i-1) != 0){
          f+=k/(int)pow(10,i-1);
          k=k%(int)pow(10,i-1);
        }
      }
      
      if(N%f==0){
        cout << "Yes" << endl ;
      }else{
        cout << "No" << endl ;
      }
    }