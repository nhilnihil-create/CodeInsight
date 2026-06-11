#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
   long long int n;
   cin>>n;
   vector<string> hoge(n);
   for(long long int i=0; i<n; i++){
     cin>>hoge.at(i);
   }
   map<string,long long int> huga;
   huga[hoge.at(0)]++;
   char last=hoge.at(0)[hoge.at(0).size()-1];
   bool ok=true;
   for(long long int i=1; i<n; i++){
     if(huga.count(hoge.at(i))){
       ok=false;
       break;
     }
     huga[hoge.at(i)]++;
     if(last!=hoge.at(i)[0]){
       ok=false;
       break;
     }
     last=hoge.at(i)[hoge.at(i).size()-1];
   }
   if(ok){
     cout<<"Yes"<<endl;
   }else{
     cout<<"No"<<endl;
   }
}