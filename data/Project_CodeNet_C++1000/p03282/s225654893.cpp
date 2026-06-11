#include<iostream>
#include<string>
using namespace std;

int f(int y){
    int ans = 1;
    for(int i = 0;i < y;i++){
        ans *= 10;
    }

    return ans;
}

/*xのy乗*/
long long g(int x,int y){
    long long ans = 1;
    for(int i = 0;i < y;i++){
        ans *= x;
    }

    return ans;

}

int main(){
    string s;
    long long k;
    cin >> s >> k;
    /**/
   int c[100];
   long long d[100];

   for(int i = 0;i < s.size();i++){
       c[i] = s.at(i) - '0';
   }
   /**/

   int ccount = 0;

   for(int i = 0;i < s.size();i++){
       if(c[i] == 1){
           ccount++;
           if(k == ccount){
               cout << c[i] << endl;
               break;
           }
           else if(c[i + 1] > 1){
               cout << c[i + 1] << endl;
               break;
           }
       }
     else{
       cout << c[i] << endl;
       break;
     }
   }

    return 0;
}