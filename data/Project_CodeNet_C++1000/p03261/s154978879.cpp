#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <map>
#include <utility>

using namespace std;


int main(){
    int n;
     cin >> n;
     vector<string> s(n);

     string pre = "";
     string now = "";

     bool flag = true;
     
     for(int i = 0 ; i < n; i++){
         cin >> s[i];
         now = s[i];
         if(i != 0 ){

             if(now[0] != pre[pre.length()-1]){
                 flag = false;
                 //cout << "a";
             }
         }
         pre = now;

     }


     for(int i = 0; i < n; i++){
         if(count(s.begin(), s.end(), s[i]) > 1){
             flag = false;
         }
     }


     if(flag){
         cout << "Yes" << endl;
     }else{
         cout << "No" << endl;
     }

}