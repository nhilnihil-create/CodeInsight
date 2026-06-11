    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int vec[4] = {0,0,0,0};
      int i,kai=0,cv[6];
      for(i=0;i<6;i++)cin >> cv[i];
      
      for(i=0;i<6;i++){
       	 if(cv[i] == 1)vec[0]++;
     	 if(cv[i] == 2)vec[1]++;
     	 if(cv[i] == 3)vec[2]++;
     	 if(cv[i] == 4)vec[3]++;
      }
      for(i=0;i<4;i++){
        if(vec[i] <= 0 || vec[i] > 2)kai = 1; 
      }
      if(kai == 0)cout << "YES" << endl;
      else cout << "NO" << endl;
      
    }
