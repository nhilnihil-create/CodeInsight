#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string str,str1,str2;
    cin>> str;
    
    str1 = str.substr(0,2);
    str2 = str.substr(2,2);
  
    if (stoi(str1)<=12 && stoi(str1)>0 && stoi(str2)<=12 && stoi(str2)>0)
        cout<<"AMBIGUOUS";   
    else if(stoi(str1)<=12 && stoi(str1)>0)
        cout<<"MMYY";
    else if(stoi(str2)<=12 && stoi(str2)>0)
        cout<<"YYMM";
    else
        cout<<"NA";
   
    return 0;
}