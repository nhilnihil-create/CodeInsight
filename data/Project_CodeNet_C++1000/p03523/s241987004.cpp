#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iomanip>
#include <tuple>

using namespace std;

int main(){
   string s;
   cin>>s;
   int cnt=0;
   int p=0;
   string t="KIHBR";

   for(int i=0;i<s.size();i++){
       if(s[i]==t[p]){
           p++;
           cnt=0;
       }
       else if(cnt==0 && s[i]=='A' && s[i+1]!='I' && s[i-1]!='I')cnt++;
       else {
           cout<<"NO"<<endl;
           return 0;
       }
   }
   if(p!=5){
       cout<<"NO"<<endl;
       return 0;
   }
   cout<<"YES"<<endl;
}

   
