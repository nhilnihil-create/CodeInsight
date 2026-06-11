#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int>vec(5);
    for(int i=0;i<5;i++){
        cin >>vec.at(i);
    }
    sort(vec.begin(),vec.end());
    int A=9999999;
    int B=0;
    do{
        int B=0;
       for(int i=0;i<4;i++){
           if(vec.at(i)%10==0){
             B+=vec.at(i);
                 }
           else{
            B+=(vec.at(i)/10+1)*10;
            }  
    } 
    B+=vec.at(4);
    A=min(A,B) ; 
    }while(next_permutation(vec.begin(),vec.end()));
    cout << A <<endl;
}