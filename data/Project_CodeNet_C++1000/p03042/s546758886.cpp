#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   string s,a="",b="";
   int l=0,r=0;
   cin >> s;

   a = s[0];
   a += s[1];
   b = s[2];
   b += s[3];
   
   l = stoi(a);
   r = stoi(b);
   
   if(l > 12){
     if(r <= 12 && r!= 0) cout << "YYMM" << endl;
     else cout << "NA" << endl;
   }
   else if(l == 0){
       if(r == 0) cout << "NA" << endl;
       else if(r <= 12) cout << "YYMM" << endl;
       else cout << "NA" << endl;
   }
   else{
       if(r == 0)  cout << "MMYY" << endl;
       else if(r <= 12) cout << "AMBIGUOUS" << endl;
       else cout << "MMYY" << endl;
   }
}