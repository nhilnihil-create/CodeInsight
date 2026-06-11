     #include<iostream>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<algorithm>
    #include<string>
    #include<math.h>
    #include<sstream>
    #include<set>
    #include<map>
    using namespace std;
    #define INF 10000000;
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define vec(n) vector<int> vec(n)
    #define vvec(m,n) vector<vector<int>> vec(m,vector(n))

    int main(){
      int a,b,c,x,y,sum = 0;
      bool f = true;
      cin >> a >> b >> c >> x >> y;
      
      while(x>0 && y>0){
        if(c*2 >= a+b){
          sum += a+b;
          x--;
          y--;
        }

        if(c*2 < a+b){
          sum += c*2;
          x--;
          y--;
        }
      }

      
        while(x>0){
          if(c*2 > a){
            sum += a;
            x--;
          }

          if(c*2 < a){
            sum += c*2;
            x--;
          }
        }



        while(y>0){
          if(c*2 > b){
            sum += b;
            y--;
          }

          if(c*2 < b){
            sum += c*2;
            y--;
          }
        }
      
      cout << sum <<endl;

    }
    