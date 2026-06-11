#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>> N;
    string s="No";
    int c,d;
    for (int i = 0; i <=25 ; i++)
    {
        for (int j = 0; j <15 ; j++)
        {
            int total=4*i+7*j;
           if (N==total)
           {
               s="Yes";
           }
           
        }
        
    }
    cout<< s<< endl;
}