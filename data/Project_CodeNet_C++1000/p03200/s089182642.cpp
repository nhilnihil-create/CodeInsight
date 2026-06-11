#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >>S;
    long long isi=0,count=0;
    for(int i=0;i<S.size();i++){
       if(S.at(i)=='B'){
           isi++;
       }
       else{
           count+=isi;
       }
    }
    cout << count <<endl;
}