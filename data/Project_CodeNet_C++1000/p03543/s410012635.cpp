    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int N;
      cin >> N;
      int a1,a2,a3,a4;
      a1=N/1000;
      a2=(N%1000)/100;
      a3=((N%1000)%100)/10;
      a4=((N%1000)%100)%10;
     
      if (a1 == a2 && a2 == a3) {
        cout << "Yes" << endl;
      }
      else if(a2 == a3 && a3 == a4){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
          
    }