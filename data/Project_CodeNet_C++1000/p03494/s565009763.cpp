    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int N;
      cin >> N;
      int count=0;
      int min=30;
      int k=0;
      
      // ここにプログラムを追記
      for(int i=0;i<N;i++){
        cin >> k ;
        count=0;
        while(k%2==0){
          k/=2;
          count++;
        }
        if(count<min){
          min=count;
        }
      }
      cout << min << endl;
      
    }